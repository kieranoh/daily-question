#include <stdio.h>
#include <stdlib.h>

int map[21][21] = {0};
int n;
int s_x, s_y,s_size = 2;
int eat = 0;
int result = 0;
typedef struct Node
{
    int x;
    int y;
    int idx;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
    int cnt;
}Queue;

void init_queue(Queue *queue) {
    queue->front = queue->rear = NULL;
    queue->cnt = 0;
}

int is_empty(Queue *queue){
    return queue->cnt ==0;
}

void push_queue(Queue *queue, int x, int y, int idx) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    temp->idx = idx;
    temp->next = NULL;

    if(is_empty(queue)) {
        queue->front = temp;
    }
    else{
        queue->rear->next = temp;
    }
    queue->rear = temp;
    queue->cnt++;

}

void pop_queue(Queue *queue){
    Node *temp = queue->front;
    queue->front = temp->next;
    free(temp);
    queue->cnt--;
}


int find_way() {
    int history[21][21] = {0};
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    Queue find;
    init_queue(&find);
    push_queue(&find,s_x,s_y,0);
    history[s_y][s_x]=1;

    int fish_dist = -1;
    int cand_x = 0; int cand_y = 0;
    while(!is_empty(&find)){

        int temp_x = find.front->x;
        int temp_y = find.front->y;
        int temp_idx = find.front->idx;
        //printf("%d : go to %d %d     \n",temp_idx,temp_y,temp_x);
        pop_queue(&find);

        if(fish_dist != -1 && temp_idx > fish_dist) break;
        
        if(map[temp_y][temp_x]<s_size&& map[temp_y][temp_x] !=0){
            if(fish_dist == -1) {
                fish_dist = temp_idx;
                cand_x = temp_x;
                cand_y = temp_y;
            }
            else{
                if(temp_y < cand_y || (temp_y == cand_y && temp_x < cand_x)) {
                    cand_x = temp_x;
                    cand_y = temp_y;
                }
            }
            
        }
        for(int i=0; i<4; i++){
            int nx = temp_x + dx[i];
            int ny = temp_y + dy[i];
            //printf("new y new x is %d %d\n",ny,nx);
            if(nx<0 || nx >= n || ny < 0 || ny >= n) continue;
            if(history[ny][nx]==1) continue;
            if(map[ny][nx]>s_size) continue;

            history[ny][nx] = 1;            
            
            push_queue(&find,nx,ny,temp_idx+1);
        }
    }

    while(!is_empty(&find)){
        pop_queue(&find);
    }
    if(fish_dist==-1) return -1;

    s_x = cand_x;
    s_y = cand_y;
    result += fish_dist;
    eat++;
    map[cand_y][cand_x] = 0;

    return 1;
}

void play(){
    Queue queue;
    while(find_way()!=-1){
        //printf("shark is in %d %d\n",s_y,s_x);
        if(eat==s_size){
            s_size++;
            eat=0;
        }
    }
}

int main(){
    scanf("%d",&n);

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++) {
            scanf("%d",&map[i][j]);
            if(map[i][j]==9){
                s_x = j;
                s_y = i;
                map[i][j] = 0;
            }
        }
    }

    //printf("shar is in %d %d\n",s_y,s_x);

    play();
    printf("%d\n",result);

    return 0;
}