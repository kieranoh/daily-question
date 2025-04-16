#include <stdio.h>

int map[51][51] = {0};
int temp_ar[51][51] = {0};

int a_1=-1,a_2=-1;

int r,c;

void copy(int from[51][51], int to[51][51]){
    for(int i=0; i< r; i++){
        for(int j=0; j<c;j++){
            to[i][j] = from[i][j];
        }
    }
}

void init_temp() { 
    for(int i=0; i< r; i++){
        for(int j=0; j<c;j++){
            temp_ar[i][j] = 0;
        }
    }
}


void print_map(){
    printf("------------------\n");
    for(int i=0; i< r; i++){
        for(int j=0; j<c;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
void spread(){
    init_temp();
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for(int i=0; i< r; i++){
        for(int j=0; j<c;j++){
            if(map[i][j]>0){
                int temp = map[i][j]/5;
                int cnt = 0;
                for(int d=0; d<4;d++){
                    int nx = j+dx[d];
                    int ny = i+dy[d];
                    if(nx <0 || nx >= c || ny <0 || ny >= r) continue;
                    if(map[ny][nx]==-1) continue;
                    temp_ar[ny][nx] += temp;
                    cnt++;
                }

                temp_ar[i][j] += map[i][j] - temp * cnt;
            }
        }
    }

    temp_ar[a_1][0] = -1;
    temp_ar[a_2][0] = -1;
    copy(temp_ar,map);
}

void play(){


    spread();
    //print_map();
    for(int i=a_1 -1;i>=0;i--){
        map[i+1][0] = map[i][0];
    }
    for(int i=0; i<c-1;i++){
        map[0][i] = map[0][i+1];
    }
    for(int i=0; i<a_1;i++){
        map[i][c-1] = map[i+1][c-1];
    }
    for(int i=c-1; i>1; i--){
        map[a_1][i] = map[a_1][i-1];
    }
    map[a_1][1] = 0;
    map[a_1][0] = -1;

    for(int i=a_2+1;i<r-1;i++){
        map[i][0] = map[i+1][0];
    }
    for(int i=0; i<c-1;i++){
        map[r-1][i] = map[r-1][i+1];
    }
    for(int i=r-1; i>a_2;i--){
        map[i][c-1] = map[i-1][c-1];
    }
    for(int i=c-1; i>1; i--){
        map[a_2][i] = map[a_2][i-1];
    } 
    map[a_2][1] = 0;
    map[a_2][0] = -1;

    //print_map();

}

int count(){
    int result=0;
    for(int i=0; i< r; i++){
        for(int j=0; j<c;j++){
            if(map[i][j]>0)   result += map[i][j];
        }
    }
    return result;
}

int main(){
    int t;
    int result = 0;
    scanf("%d %d %d",&r,&c,&t);

    for(int i=0; i<r;i++) {
        for(int j=0; j<c;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==-1) {
                if(a_1==-1) a_1 = i;
                else a_2 = i;
            }
        }
    }
    //printf("------------------\n");
    for(int i=0; i<t;i++){
        play();
    }

    result = count();

    printf("%d",result);

    return 0;
}