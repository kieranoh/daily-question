#include <stdio.h>
#include <stdlib.h>

int n,m;
int map[50][50];
int history[50][50] = {10};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int result=999999;


void init_history(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            history[i][j]=0;
        }
    }
}

void print_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

int calcCityDistance() {
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (map[i][j] == 1) {  
                int houseDist = 987654321;
                for (int a = 0; a < n; a++){
                    for (int b = 0; b < n; b++){
                        if (map[a][b] == 2) {
                            int d = abs(i - a) + abs(j - b);
                            houseDist = houseDist > d ? d : houseDist;
                        }
                    }
                }
                sum += houseDist;
            }
        }
    }
    return sum;
}

void remove_ck(int cnt,int x,int y){
    if(cnt==0){
        int score = calcCityDistance();
        //printf("score is %d\n",score);
        //printf("---------------\n");
        //print_map();
        result = result > score ? score : result;
        return;
    }

    for(int i=y; i<n;i++){
        for(int j=(i==y ? x : 0);j<n;j++){
            if(map[i][j]==2){
                map[i][j]= 0 ;
                remove_ck(cnt-1,j,i);
                map[i][j]= 2;
            }
            
        }
    }
}



int main() {
    scanf("%d %d",&n,&m);
    int cnt = 0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==2) cnt++;
        }
    }

    remove_ck(cnt-m,0,0);

    printf("%d",result);

    return 0;
}