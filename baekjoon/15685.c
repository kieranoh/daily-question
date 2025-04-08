#include <stdio.h>

int map[101][101] = {0};

int history [4][20] = {0}; //x,y,d,g

int pow_2 [11] = {1,2,4,8,16,32,64,128,256,512,1024};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};  

int d_root[1025] = {0};

void print_root (int n) {
    for(int i=0; i<pow_2[n];i++){
        printf(" %d ",d_root[i]);
    }
    printf("\n");
}

void print_map(){
    printf("    ");
    for(int i=0;i<8;i++) printf(" %d ",i);
    printf("\n");
    for(int i=0; i<8;i++){
        printf("%d - ",i);
        for(int j=0; j<8;j++){
            printf(" %d ",map[i][j]);
        }
        printf("\n");
    }
}

void init_root(){
    d_root[0] = 0;
    for(int i=1; i<1025;i++){
        d_root[i]=-1;
    }
}

void make_root(int n){
    int temp = n;
    int min = pow_2[temp-1]-1;
    while (d_root[min!=-1])
    {
        temp--;
        min = pow_2[temp-1]-1;
    }
    for(int i = temp;temp<n;temp++){
        make_root(temp);
    }
    
    int idx = pow_2[n-1];
    int target = idx;
    idx--;
    for(int i = target;i<(target)*2;i++){
        d_root[i] = (d_root[idx]+1)%4;
        idx = idx-1;
    }
}

int get_score(){
    int result = 0;

    for(int i=0; i<100; i++){
        for(int j= 0 ; j<100; j++){
            if(map[i][j]==1 && map[i+1][j]==1 && map[i][j+1]==1 && map[i+1][j+1]==1){
                result++;
            }
        }
    }

    return result;
}

void dg_move(int tc){
    for(int i=0; i<tc;i++){
        int x = history[0][i];
        int y = history[1][i];
        int d = history[2][i];
        int g = history[3][i];
        if(d_root[pow_2[g]]==-1){
            make_root(g);
        }
        // printf("---------------\n");
        // print_root(g);
        // printf("---------------\n");
        // print_map();
        map[y][x] = 1;
        for(int i =0; i<pow_2[g];i++){
            int temp = (d_root[i] + d) %4;
            x = x + dx[temp];
            y = y + dy[temp];
            map[y][x] = 1;
        }

    }
}

int main() {

    int tc = 0;
    scanf("%d",&tc);
    for(int i=0; i<tc;i++){
        scanf("%d %d %d %d",&history[0][i],&history[1][i],&history[2][i],&history[3][i]);
    }
    init_root();

    dg_move(tc);
    int result = get_score();

    printf("%d\n",result);

    return 0;
}