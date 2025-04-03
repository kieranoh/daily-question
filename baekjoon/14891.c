#include <stdio.h>

int scr[8][4] = {0};
int his[6] = {0};

void print_scr(){

    printf("__1_______2________3_______4__\n");
    printf("  %d     %d     %d     %d  \n",scr[0][0],scr[0][1],scr[0][2],scr[0][3]);
    printf(" %d %d   %d %d   %d %d   %d %d \n",scr[7][0],scr[1][0],scr[7][1],scr[1][1],scr[7][2],scr[1][2],scr[7][3],scr[1][3]);
    printf("%d   %d %d   %d %d   %d %d   %d\n",scr[6][0],scr[2][0],scr[6][1],scr[2][1],scr[6][2],scr[2][2],scr[6][3],scr[2][3]);
    printf(" %d %d   %d %d   %d %d   %d %d \n",scr[5][0],scr[3][0],scr[5][1],scr[3][1],scr[5][2],scr[3][2],scr[5][3],scr[3][3]);
    printf("  %d     %d     %d     %d  \n",scr[4][0],scr[4][1],scr[4][2],scr[4][3]);
    printf("__________\n");
    
}

void move_left(int idx, int d) {
    if(idx<0) return;
    if (his[idx*2]!= his[idx*2+1]) {
        if (d == 1) {
            int temp = scr[0][idx];
            for (int i = 0; i <= 6; i++) {
                scr[i][idx] = scr[i + 1][idx];
            }
            scr[7][idx] = temp;
        }
        else {
            int temp = scr[0][idx];
            scr[0][idx] = scr[7][idx];
            for (int i = 7; i >= 2; i--) {
                scr[i][idx] = scr[i - 1][idx];
            }
            scr[1][idx] = temp;
        }

        move_left(idx - 1, d * -1);

    }
    return;
}

void move_right(int idx, int d) {
    if(idx>=4) return;
    if (his[(idx-1)*2] != his[(idx-1)*2+1]) {
        if (d == -1) {

            int temp = scr[0][idx];
            scr[0][idx] = scr[7][idx];
            for (int i = 7; i >= 2; i--) {
                scr[i][idx] = scr[i - 1][idx];
            }
            scr[1][idx] = temp;
        }
        else {
            int temp = scr[0][idx];
            for (int i = 0; i <= 6; i++) {
                scr[i][idx] = scr[i + 1][idx];
            }
            scr[7][idx] = temp;
        }

        move_right(idx +1, d * -1);

    }
    return;
}

void move(int idx,int d){
    if (d == 1) {
        int temp = scr[0][idx];
        scr[0][idx] = scr[7][idx];
        for (int i = 7; i >= 2; i--) {
            scr[i][idx] = scr[i - 1][idx];
        }
        scr[1][idx] = temp;
    }
    else {
        int temp = scr[0][idx];
        for (int i = 0; i <= 6; i++) {
            scr[i][idx] = scr[i + 1][idx];
        }
        scr[7][idx] = temp;
    }
    if(idx!=0) move_left(idx-1,d);
    if(idx!=3) move_right(idx+1,d);

}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%1d", &scr[j][i]);
        }
    }
    his[0] = scr[2][0];
    for(int i=1;i<3;i++){
        his[i*2-1] = scr[6][i];
        his[i*2] = scr[2][i];
    }
    his[5] = scr[6][3];

    int cnt = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        //print_scr();
        int idx,d;
        scanf("%d %d",&idx,&d);
        move(idx-1,d);
        his[0] = scr[2][0];
        for(int i=1;i<3;i++){
        his[i*2-1] = scr[6][i];
        his[i*2] = scr[2][i];
        }
        his[5] = scr[6][3];
    }
    //print_scr();
    int sum =0; 
    int score[4] = {1,2,4,8};
    for(int i=0;i<4;i++){
        if(scr[0][i]==1) sum+=score[i];
    }

    printf("%d",sum);

}