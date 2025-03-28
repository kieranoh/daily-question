#include <stdio.h>

int map[501][501] = {0};
int visited[501][501];
int n,m;
int ans;

int block_1( int x, int y) {
    int temp = map[y][x];
    int max = temp;
    if(x+2 < m) {//
        if(y>=1) {//ㅗ
            temp+=map[y][x+1]+map[y][x+2]+map[y-1][x+1];
            max = temp>max ? temp : max;
        }
        if(y+1<n) {//ㅜ
            temp = map[y][x]+ map[y][x+1]+map[y][x+2]+map[y+1][x+1];
            max = temp>max ? temp : max;
        }
    }
    if(y+2 < n) {
        if(x>=1) {//ㅓ
            temp=  map[y][x]+map[y+1][x]+map[y+2][x]+map[y+1][x-1];
            max = temp>max ? temp : max;
        }
        if(x+1<m) {//ㅏ
            temp = map[y][x]+ map[y+1][x]+map[y+2][x]+map[y+1][x+1];
            max = temp>max ? temp : max;
        }
    
    }

    return max;
}

int make_blocks(int x, int y, int num, int sum) {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    if(num==0) {
        if(ans<sum) ans = sum;
        return 0;
    }
    for(int i=0; i<4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x >= m || new_x <0 || new_y >= n || new_y < 0) {
            continue;
        }
        if(visited[new_y][new_x]!=1) {
            visited[new_y][new_x] =1;
            make_blocks(new_x,new_y,num-1,sum+map[new_y][new_x]);
            visited[new_y][new_x] = 0;
        }
    }
    return 0;
}

int search() {
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++) {
            visited[i][j] = 1;
            make_blocks(j,i,4-1,map[i][j]);
            visited[i][j] = 0;
            int block = block_1(j,i);
            ans = ans>block ? ans : block;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&n,&m);
    int sum = 0;

    for(int i=0 ; i<n; i++){
        for(int j=0; j<m; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    search();

    printf("%d",ans);
}