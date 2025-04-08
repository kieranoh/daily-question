#include <stdio.h>

int n,m,h;
int ans = -1;

int link_list[11][31] = {0};

void print_list(){
    for(int j=0 ;j<h;j++) {
        for(int i=0;i<n;i++){
            printf(" %d ",link_list[i][j]);
        }
        printf("\n");
    }
}

void print_map(int map[11][31]){
    for (int i=0; i<n;i++){
        printf("%d  ",i+1);
    }
    printf("\n");
    for(int i=0; i<h;i++){
        for(int j=0;j<n;j++){
            printf("|");
            if(map[j][i]==1){
                printf("-");
            }
            else printf(" ");
        }
        printf("\n");
        
    }
}

int move(int map[11][31]) {
    //print_list();
    for(int i=0; i<n; i++){
        int pos = i;
        for(int j=0; j<h;j++){
            if(pos < n-1 && map[pos][j]==1){
                pos = pos+1;
                //printf("%d : %d move to %d\n",i,pos-1,pos);
            }
            else if(pos > 0 && map[pos-1][j]==1){
                pos = pos-1;
                //printf("%d : %d move to %d\n",i,pos+1,pos);
            }
        }
        if(pos!=i){
            return -1;
        }
    }

    return 1;
}


void dfs(int cnt, int start) {
    //print_map(link_list);
    if(cnt>=4){
        return;
    }
    if(move(link_list)==1){
        if(ans==-1 || ans>cnt) ans = cnt;
        if(ans==0) return;
    }

  for(int pos = start;pos < h*(n-1);pos++){
    int row = pos/ (n-1);
    int col = pos % (n-1);

    if(link_list[col][row]==1) continue;
    if(col >0 && link_list[col-1][row]==1) continue;
    if(col < n-2 && link_list[col+1][row]==1) continue;

    link_list[col][row] = 1;
    dfs(cnt+1, pos+1);
    link_list[col][row]=0;
  }



}

int main(){
    scanf("%d %d %d",&n,&m,&h);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d",&a,&b);
        link_list[b-1][a-1] = 1;
    }

    dfs(0,0);

    printf("%d",ans);

    return 0;
}