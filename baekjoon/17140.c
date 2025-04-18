#include <stdio.h>
#include<stdlib.h>

int map[101][101] = {0};
int temp_map[101][101] = {0};

int max_r = 3;
int max_c = 3;

void print_map(){
    printf("-----------\n");
    for(int i=0; i<max_r;i++){
        for(int j=0; j<max_c;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
typedef struct Node
{
    int num;
    int cnt;
}Node;

Node history[101];

int cmp(const void *a, const void *b){
    Node *t1 = (Node *)a;
    Node *t2 = (Node *)b;
    if(t1->cnt != t2->cnt) return t1->cnt - t2->cnt;
    return t1->num - t2->num;
}


void init_history(){
    for(int i=0; i<101;i++){
        history[i].num = 0;
        history[i].cnt = 0;
    }
}

void init_map (int reset[101][101]){
    for(int i=0; i<101;i++){
        for(int j=0; j<101; j++){
            reset[i][j] = 0;
        }
    }
}

void copy_map(int from[101][101], int to[101][101]){
    init_map(to);
    for(int i=0; i<max_r;i++){
        for(int j=0; j<max_c;j++){
            to[i][j] = from[i][j];
        }
    }
}

void get_count(int idx) {
    init_map(temp_map);
    
    if(idx==0){
        int next_c=0;
        for(int i=0; i<max_r;i++){
            init_history();
            int temp_max_c = 0;
            for(int j=0; j<max_c; j++){
                if(map[i][j]==0) continue;
                history[map[i][j]].num = map[i][j];
                history[map[i][j]].cnt++;
            }


            qsort(history,101,sizeof(Node),cmp);

            
            for(int j=0; j<101; j++){
                if(history[j].num!=0){
                    temp_map[i][temp_max_c] = history[j].num;
                    temp_map[i][temp_max_c+1] = history[j].cnt;
                    temp_max_c = temp_max_c+2;
                    //printf("!\n");
                }
            }
            next_c = next_c > temp_max_c ? next_c : temp_max_c;
            next_c = next_c > 100 ? 100 : next_c;
        }
        max_c = next_c;
        //printf("max_c = %d\n",max_c);
        copy_map(temp_map,map);
    }

    if(idx==1){
        int next_r=0;
        for(int j=0; j<max_c;j++){
            init_history();
            int temp_max_r = 0;
            for(int i=0; i<max_r; i++){
                if(map[i][j]==0) continue;
                history[map[i][j]].num = map[i][j];
                history[map[i][j]].cnt++;
            }

            qsort(history,101,sizeof(Node),cmp);
            
            for(int i=0; i<101; i++){
                if(history[i].num!=0){
                    temp_map[temp_max_r][j] = history[i].num;
                    temp_map[temp_max_r+1][j] = history[i].cnt;
                    temp_max_r = temp_max_r+2;
                }
            }
            next_r = next_r > temp_max_r ? next_r : temp_max_r;
            next_r = next_r > 100 ? 100 : next_r;
        }
        max_r = next_r;
        copy_map(temp_map,map);
    }
}


int main() {

    int r,c,k;
    int cnt = 0;
    int falg = 0;
    scanf("%d %d %d",&r, &c,&k);

    for(int i=0; i<max_r;i++){
        for(int j=0; j<max_c;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(cnt;cnt<101;cnt++)
    {
        if(map[r-1][c-1]==k) {
            falg = 1;
            break;
        }
        if(max_c <= max_r) get_count(0);
        else get_count(1);
        //print_map();
    }
    if(falg==0) printf("-1");
    else printf("%d",cnt);

    return 0;
}