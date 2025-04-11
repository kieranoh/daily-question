#include <stdio.h>
#include <stdlib.h>

int map[51][51] = {0};
int n,l,r;
int result = 0;
int history[51][51] = {0};

typedef struct Node
{
    int x;
    int y;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
    int cnt;
}Queue;

void init_history(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            history[i][j] = 0;
        }
    }
}

void init_queue(Queue *queue) {
    queue->front = queue->rear = NULL;
    queue->cnt = 0;
}

int Is_empty(Queue *queue){
    return queue->cnt ==0;
}

void push_queue(Queue *queue,int x, int y) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    if(Is_empty(queue)) queue->front = temp;
    else  queue->rear->next = temp;
    queue->rear =  temp;
    
    queue->cnt++;
}

void pop_queue(Queue *queue) {
    Node* temp = queue->front;
    queue->front = temp->next;
    free(temp);
    queue->cnt--;
}



int move() {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    init_history();
    int movement_occurred = 0;  

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (history[i][j]) continue;  

            Queue q;
            init_queue(&q);
            
            Queue unionQ;
            init_queue(&unionQ);

            push_queue(&q, j, i);       // x: j, y: i
            push_queue(&unionQ, j, i);

            history[i][j] = 1;

            int union_sum = map[i][j];  
            int union_count = 1;        

            while (!Is_empty(&q)) {
                int curX = q.front->x;
                int curY = q.front->y;
                pop_queue(&q);

                
                for (int dir = 0; dir < 4; dir++){
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (history[ny][nx]) continue;
                    int diff = abs(map[curY][curX] - map[ny][nx]);
                    if(diff < l || diff > r) continue;

                    
                    push_queue(&q, nx, ny);
                    push_queue(&unionQ, nx, ny);
                    history[ny][nx] = 1;
                    union_sum += map[ny][nx];
                    union_count++;
                }
            }
            
            if (union_count > 1) {
                movement_occurred = 1;
                int new_pop = union_sum / union_count;
                
                while (!Is_empty(&unionQ)) {
                    int ux = unionQ.front->x;
                    int uy = unionQ.front->y;
                    pop_queue(&unionQ);
                    map[uy][ux] = new_pop;
                }
            } else {
                
                while (!Is_empty(&unionQ)) {
                    pop_queue(&unionQ);
                }
            }
        }
    }
    if (movement_occurred) result++;
    return movement_occurred;
}

int main() {
    scanf("%d %d %d",&n,&l,&r);

    for(int i=0; i<n; i++){
        for(int j=0 ; j<n; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    while(move()!=0){
    }

    printf("%d",result);

    return 0;
}
