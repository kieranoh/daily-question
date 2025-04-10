#include <stdio.h>

void clockwise(char face[3][3]) {
    char temp;
    // 모서리 회전
    temp = face[0][0];
    face[0][0] = face[2][0];
    face[2][0] = face[2][2];
    face[2][2] = face[0][2];
    face[0][2] = temp;
    // 변(edge) 회전
    temp = face[0][1];
    face[0][1] = face[1][0];
    face[1][0] = face[2][1];
    face[2][1] = face[1][2];
    face[1][2] = temp;
}

void U(char cube[6][3][3]) {
    int i, j;
    char tmp[3][3];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            tmp[i][j] = cube[5][i][j];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[5][i][j] = cube[0][i][j];
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[0][i][j] = cube[4][i][j];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[4][i][j] = cube[1][i][j];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[1][i][j] = tmp[i][j];

    clockwise(cube[1]); 
    clockwise(cube[1]); 
    clockwise(cube[4]); 
    clockwise(cube[4]); 
    clockwise(cube[2]); 
    clockwise(cube[3]); 
    clockwise(cube[3]); 
    clockwise(cube[3]);
}

void F(char cube[6][3][3]) {
    int i, j;
    char tmp[3][3];
    // cube[2] → tmp
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            tmp[i][j] = cube[2][i][j];
    // cube[5] → cube[2]
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[2][i][j] = cube[5][i][j];
    // cube[3] → cube[5]
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[5][i][j] = cube[3][i][j];
    // cube[4] → cube[3]
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[3][i][j] = cube[4][i][j];
    // tmp → cube[4]
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cube[4][i][j] = tmp[i][j];

    // 회전 적용
    clockwise(cube[2]);
    clockwise(cube[4]);
    clockwise(cube[3]);
    clockwise(cube[5]);
    clockwise(cube[1]);
    clockwise(cube[1]);
    clockwise(cube[1]);
    clockwise(cube[0]);
}

void L(char cube[6][3][3]) {
    int i;
    char temp[3];
    // 좌측 열(column) 교환: 0 → 3 → 1 → 2
    for (i = 0; i < 3; i++) {
        temp[i] = cube[0][i][0];
        cube[0][i][0] = cube[3][i][0];
        cube[3][i][0] = cube[1][i][0];
        cube[1][i][0] = cube[2][i][0];
        cube[2][i][0] = temp[i];
    }
    clockwise(cube[4]);
}

void R(char cube[6][3][3]) {
    int i;
    char temp[3];
    // 우측 열(column) 교환: 0 → 2 → 1 → 3
    for (i = 0; i < 3; i++) {
        temp[i] = cube[0][i][2];
        cube[0][i][2] = cube[2][i][2];
        cube[2][i][2] = cube[1][i][2];
        cube[1][i][2] = cube[3][i][2];
        cube[3][i][2] = temp[i];
    }
    clockwise(cube[5]);
}

int main(void) {
    int T, n, i, j, k;
    char move[3];  // 각 조작은 예: "U+" 또는 "F-"
    
    scanf("%d", &T);
    while (T--) {
        char cube[6][3][3];
        // 초기 큐브 설정: 면마다 고유 문자 할당
        // cube[0]: white ('w'), cube[1]: yellow ('y'),
        // cube[2]: red ('r'), cube[3]: orange ('o'),
        // cube[4]: green ('g'), cube[5]: blue ('b')
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++) {
                cube[0][i][j] = 'w';
                cube[1][i][j] = 'y';
                cube[2][i][j] = 'r';
                cube[3][i][j] = 'o';
                cube[4][i][j] = 'g';
                cube[5][i][j] = 'b';
            }
        
        scanf("%d", &n);
        while(n--) {
            scanf("%s", move);
            k = 1;
            if (move[1] == '-')
                k = 3;
            
            if (move[0] == 'U') {
                U(cube);
                for (j = 0; j < k; j++)
                    R(cube);
                for (j = 0; j < 3; j++)
                    U(cube);
            }
            else if (move[0] == 'D') {
                U(cube);
                for (j = 0; j < k; j++)
                    L(cube);
                for (j = 0; j < 3; j++)
                    U(cube);
            }
            else if (move[0] == 'F') {
                F(cube);
                for (j = 0; j < k; j++)
                    L(cube);
                for (j = 0; j < 3; j++)
                    F(cube);
            }
            else if (move[0] == 'B') {
                F(cube);
                for (j = 0; j < k; j++)
                    R(cube);
                for (j = 0; j < 3; j++)
                    F(cube);
            }
            else if (move[0] == 'L') {
                for (j = 0; j < k; j++)
                    L(cube);
            }
            else if (move[0] == 'R') {
                for (j = 0; j < k; j++)
                    R(cube);
            }
        }
        // 결과 출력: 큐브의 윗면 (cube[0])
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++)
                printf("%c", cube[0][i][j]);
            printf("\n");
        }
    }
    return 0;
}
