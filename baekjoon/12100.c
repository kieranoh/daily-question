#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindMax(int** map, int n){
    int max = 0;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(map[i][j] > max) {
                max = map[i][j];
            }
        }
    }
    return max;
}


void copy_map(int** dest, int** src, int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dest[i][j] = src[i][j];
}

void MoveUp(int** map, int n) {
    for (int col = 0; col < n; col++) {
        int top = 0;
        int last = 0;
        int* new_col = (int*)calloc(n, sizeof(int));

        for (int row = 0; row < n; row++) {
            if (map[row][col] == 0) continue;

            if (last != 0 && last == map[row][col]) {
                new_col[top - 1] = last * 2;
                last = 0;
            } else {
                last = map[row][col];
                new_col[top++] = last;
            }
        }

        for (int row = 0; row < n; row++) {
            map[row][col] = new_col[row];
        }

        free(new_col);
    }
}


void MoveDown(int** map, int n) {
    for (int col = 0; col < n; col++) {
        int bottom = n - 1;
        int last = 0;
        int* new_col = (int*)calloc(n, sizeof(int));

        for (int row = n - 1; row >= 0; row--) {
            if (map[row][col] == 0) continue;

            if (last != 0 && last == map[row][col]) {
                new_col[bottom + 1] = last * 2;
                last = 0;
            } else {
                last = map[row][col];
                new_col[bottom--] = last;
            }
        }

        for (int row = 0; row < n; row++) {
            map[row][col] = new_col[row];
        }

        free(new_col);
    }
}


void MoveLeft(int** map, int n) {
    for (int row = 0; row < n; row++) {
        int left = 0;
        int last = 0;
        int* new_row = (int*)calloc(n, sizeof(int));

        for (int col = 0; col < n; col++) {
            if (map[row][col] == 0) continue;

            if (last != 0 && last == map[row][col]) {
                new_row[left - 1] = last * 2;
                last = 0;
            } else {
                last = map[row][col];
                new_row[left++] = last;
            }
        }

        for (int col = 0; col < n; col++) {
            map[row][col] = new_row[col];
        }

        free(new_row);
    }
}

void MoveRight(int** map, int n) {
    for (int row = 0; row < n; row++) {
        int right = n - 1;
        int last = 0;
        int* new_row = (int*)calloc(n, sizeof(int));

        for (int col = n - 1; col >= 0; col--) {
            if (map[row][col] == 0) continue;

            if (last != 0 && last == map[row][col]) {
                new_row[right + 1] = last * 2;
                last = 0;
            } else {
                last = map[row][col];
                new_row[right--] = last;
            }
        }

        for (int col = 0; col < n; col++) {
            map[row][col] = new_row[col];
        }

        free(new_row);
    }
}


int Move(int** map, int n, int deep) {
    int score = 0;
    int temp = 0;
    if(deep == 5) {
        return FindMax(map, n);
    }

    // 동적 복사 배열 선언
    int** copy = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        copy[i] = (int*)malloc(n * sizeof(int));

    copy_map(copy, map, n);

    for (int i=0; i<4; i++){
        if(i==0){
            MoveUp(map, n);
            
        }
        if(i==1){
            MoveDown(map, n);
        }
        if(i==2){
            MoveRight(map, n);
        }
        if(i==3){
            MoveLeft(map, n);
        }

        temp = Move(map, n, deep + 1);

        copy_map(map, copy, n);  // 복구
        if(temp > score) score = temp;
    }

    for(int i = 0; i < n; i++) free(copy[i]);
    free(copy);

    return score;
}

int main(){
    int n;
    scanf("%d", &n);

    // map 동적할당
    int** map = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++)
        map[i] = (int*)malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int max_score = Move(map, n, 0);
    printf("%d\n", max_score);

    for(int i=0; i<n; i++) free(map[i]);
    free(map);

    return 0;
}
