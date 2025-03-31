#include <stdio.h>

int map[50][50] = {0};
int visited[50][50] = {0};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int n,m;

int ans=0;

void search(int x_pos, int y_pos, int d){
    
    while(1){
        int flag = 0;
        if(visited[y_pos][x_pos]==0) {
            visited[y_pos][x_pos]=1;
            ans++;
        }
        for(int i=0; i<4;i++){
            int new_X,new_y;
            int new_d = (d - i+3)%4;
            new_X = x_pos+dx[new_d];
            new_y = y_pos+dy[new_d];
            if(new_y <0 || new_y >= n || new_X <0 || new_X >=m) {
                continue;
            }
            if(map[new_y][new_X]!=1 && visited[new_y][new_X]==0){
                x_pos = new_X;
                y_pos = new_y;
                d = new_d;
                flag = 1;
                break;
            }
    
        }
        if (flag == 0){
            x_pos = x_pos+dx[(d+2)%4];
            y_pos = y_pos + dy[(d+2)%4];
            if(x_pos<0 || x_pos >= m || y_pos < 0|| y_pos >= n){
                return;
            }
            if(map[y_pos][x_pos]==1){
                return;
            }
        }
    }
    
}

int main(){
    scanf("%d %d",&n,&m);
    int x_pos, y_pos;

    int d=0; 

    scanf("%d %d %d",&y_pos,&x_pos,&d);

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }

    search(x_pos,y_pos,d);

    printf("%d",ans);

    return 0;
}