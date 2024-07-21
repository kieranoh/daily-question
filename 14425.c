#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[500];
} wd;

int compare(const void *a, const void *b) {
    return strcmp(((wd*)a)->word, ((wd*)b)->word);
}

int search(wd *arr, char target[], int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].word, target);
        if (cmp == 0) {
            return 1;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int num, input, cnt = 0;
    char temp[500];
    scanf("%d %d", &num, &input);

    wd *arr = (wd*)malloc(sizeof(wd) * num);
    for (int i = 0; i < num; i++) {
        scanf("%s", arr[i].word);
    }
    qsort(arr, num, sizeof(wd), compare);

    for (int i = 0; i < input; i++) {
        scanf("%s", temp);
        if (search(arr, temp, num) == 1) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    free(arr);

    return 0;
}
