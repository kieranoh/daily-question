#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int x;
    int y;
}Node;

typedef struct Queue {
    Node* rear;
    Node* front;
    int cnt;
}Queue;

int map[9][9] = {0};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans=0;

// void print_map(int n, int m, int temp_map[9][9]){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             printf("%d ",temp_map[i][j]);
//         }
//         printf("\n");
//     }
// }

void init_queue(Queue *queue) {
    queue->cnt = 0;
    queue->front = queue->rear =  NULL;
    
}

int is_empty(Queue *queue) {
    return queue->cnt==0;
}

void push_queue(Queue *queue, int x, int y) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    temp->next = NULL;

    if(is_empty(queue)!=0) {
        queue->front = temp;
    }
    else{
        queue->rear->next = temp;
    }
    queue->rear = temp;
    queue->cnt++;
}

void pop_queue(Queue *queue) {
    if(is_empty(queue)) return;
    Node* ptr = queue->front;
    queue->front = ptr->next;
    queue->cnt--;
    free(ptr);
}

void spread (int n, int m){
    int temp[9][9];

    Queue queue;
    init_queue(&queue);
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            temp[i][j] = map[i][j];
            if(map[i][j]==2){
                push_queue(&queue,j,i);
            }
        }
    }

    while (is_empty(&queue)==0)
    {
        int temp_x = queue.front->x;
        int temp_y = queue.front->y;

        pop_queue(&queue);

        for(int i = 0; i<4; i++){
            int new_x = temp_x + dx[i];
            int new_y = temp_y + dy[i];
            
            if(new_x <0 || new_x >=m || new_y <0 || new_y >=n) continue;

            if(temp[new_y][new_x]!=0) continue;

            temp[new_y][new_x] = 2;
            push_queue(&queue,new_x,new_y);

        }

    }

    int ans_t=0;

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(temp[i][j]==0){
                ans_t++;
            }
        }
    }
    // if(ans < ans_t){
    //     printf("--------------\n");
    //     print_map(n,m,temp);
    //     printf("--------------\n");
    // }
    ans = ans>ans_t ? ans : ans_t;

}

void make_wall(int cnt,int n, int m){
    if(cnt==3){
        spread(n,m);
        return;
    }

    for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==0) { 
                map[i][j] = 1;
                make_wall(cnt+1,n,m);
                map[i][j]=0;
            }
        }
    }
}

int main() {
    int n,m;

    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&map[i][j]);
        }
    }

    make_wall(0,n,m);

    printf("%d",ans);

}