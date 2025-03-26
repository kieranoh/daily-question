#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool map[101][101] = {0};
int exist[101][101] = {0};

typedef struct Node{
    struct Node *next;
    int x;
    int y;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
    int count;
}Queue;

void Queue_init(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->count = 0;
    return;
}

int Is_empty(Queue *queue){
    return queue->count ==0;
}

void Queue_push(Queue *queue, int x, int y){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    temp->x = x;
    temp->y = y;
    exist[y][x]++;

    if(Is_empty(queue)) {
        queue->front = temp;
    } 
    else{
        queue->rear->next = temp;
    }
    queue->rear = temp;
        queue->count++;

    return;

}

void Queue_pop(Queue *queue) {
    Node *ptr = queue->front;
    queue->front = ptr->next;
    exist[ptr->y][ptr->x]--;

    free(ptr);
    queue->count--;

    return;
}

int main() {

    int n = 0;
    int apple_count = 0;
    int turn_count = 0;

    int d=0;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    scanf("%d",&n);
    scanf("%d",&apple_count);



    for(int i=0; i<apple_count; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }

    scanf("%d",&turn_count);
    
    int turn[200][2] ;
    int turn_ptr = 0;


    for(int i=0; i<turn_count;i++) {
        char temp;

        scanf("%d %c",&turn[i][0], &temp);

        if(temp=='D') turn[i][1]=1;
        else turn[i][1] = -1;
    }

    int x_pos = 1, y_pos = 1;

    Queue queue;
    Queue_init(&queue);

    Queue_push(&queue,x_pos,y_pos);

    int cnt =0;

    while(1){
        if(cnt==turn[turn_ptr][0] && turn_ptr < turn_count) {
            d = (d+turn[turn_ptr][1] +4) %4;
            turn_ptr++;
        }

        x_pos += dx[d];
        y_pos += dy[d];


        Queue_push(&queue,x_pos,y_pos);

        if(exist[y_pos][x_pos]>1) break;

        if(y_pos<1 || x_pos <1 || y_pos > n|| x_pos > n) break;
        

        if(map[y_pos][x_pos]==true) map[y_pos][x_pos] = false;
        else Queue_pop(&queue);
        cnt++;
    }

    printf("%d",cnt+1);

    return 0;


}