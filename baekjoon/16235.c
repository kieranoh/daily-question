#include <stdio.h>
#include <stdlib.h>

#define MAX 11

typedef struct {
    int age;
} Tree;

typedef struct {
    Tree* trees;    // 나무 정보를 담은 동적 배열
    int count;      // 현재 나무의 개수
    int capacity;   // 동적 배열의 총 용량
} Cell;

int N, M, K;
int A[MAX][MAX];          // 겨울에 추가될 양분 정보
int nutrition[MAX][MAX];  // 각 칸의 현재 양분. 초기값은 5.


Cell land[MAX][MAX];


int cmp(const void *a, const void *b) {
    Tree *t1 = (Tree *)a;
    Tree *t2 = (Tree *)b;
    return t1->age - t2->age;
}

void addTree(Cell *cell, int age) {
    if (cell->count >= cell->capacity) {
        cell->capacity = (cell->capacity == 0) ? 1 : cell->capacity * 2;
        cell->trees = (Tree *)realloc(cell->trees, cell->capacity * sizeof(Tree));
    }
    cell->trees[cell->count].age = age;
    cell->count++;
}

int main(){
    int i, j, x, y, z;
    scanf("%d %d %d", &N, &M, &K);
    
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%d", &A[i][j]);
            nutrition[i][j] = 5;
            land[i][j].trees = NULL;
            land[i][j].count = 0;
            land[i][j].capacity = 0;
        }
    }
    
    for(i = 0; i < M; i++){
        scanf("%d %d %d", &x, &y, &z);
        addTree(&land[x-1][y-1], z);
    }
    
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    
    // K년 동안 시뮬레이션 수행
    for (int year = 0; year < K; year++){
        // ===== 봄 & 여름 =====
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(land[i][j].count > 0){
                    qsort(land[i][j].trees, land[i][j].count, sizeof(Tree), cmp);
                    int dead_nutrition = 0;  
                    int alive = 0;           
                    for(int t = 0; t < land[i][j].count; t++){
                        int age = land[i][j].trees[t].age;
                        if(nutrition[i][j] >= age){
                            nutrition[i][j] -= age;
                            land[i][j].trees[t].age = age + 1;
                            alive++;
                        } else {
                            dead_nutrition += age / 2;
                        }
                    }
                    nutrition[i][j] += dead_nutrition;
                    land[i][j].count = alive;
                }
            }
        }
        
        // ===== 가을 =====
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(land[i][j].count > 0){
                    for(int t = 0; t < land[i][j].count; t++){
                        if(land[i][j].trees[t].age % 5 == 0){
                            for(int d = 0; d < 8; d++){
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if(ni >= 0 && ni < N && nj >= 0 && nj < N){
                                    addTree(&land[ni][nj], 1);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        // ===== 겨울 =====
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                nutrition[i][j] += A[i][j];
            }
        }
    }
    

    long long answer = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            answer += land[i][j].count;
            free(land[i][j].trees);
        }
    }
    
    printf("%lld\n", answer);
    
    return 0;
}
