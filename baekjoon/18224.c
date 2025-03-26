#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, day, time, cnt;
} Node;

int visited[600][600][2][20] = {0}; // day: 0 (sun), 1 (moon); time: 0 ~ m-1

int map[600][600];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int capacity = n * n * 2 * m;
    Node *queue = (Node *)malloc(capacity * sizeof(Node));
    int front = 0, rear = 0;
    
    queue[rear++] = (Node){0, 0, 0, 0, 0};
    visited[0][0][0][0] = 1;
    
    int ans = -1;
    
    while(front < rear && ans == -1){
        Node cur = queue[front++];
        int x = cur.x, y = cur.y, day = cur.day, time = cur.time, cnt = cur.cnt;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            
            int ntime = (time + 1) % m;
            int nday = day;
            if(time + 1 == m) 
                nday = 1 - day;  
            
            if(map[ny][nx] == 1){
                if(day == 0)
                    continue;
                while(nx >= 0 && nx < n && ny >= 0 && ny < n && map[ny][nx] == 1){
                    nx += dx[i];
                    ny += dy[i];
                }
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
            }
            
            if(nx == n - 1 && ny == n - 1){
                ans = cnt + 1;
                break;
            }
            
            if(!visited[ny][nx][nday][ntime]){
                visited[ny][nx][nday][ntime] = 1;
                queue[rear++] = (Node){nx, ny, nday, ntime, cnt + 1};
            }
        }
        if(ans != -1)
            break;
    }
    
    free(queue);
    
    if(ans == -1){
        printf("-1");
    } else {
        int dayCount = (ans / (2 * m)) + 1;
        printf("%d %s", dayCount, ((ans / m) % 2 == 0) ? "sun" : "moon");
    }
    
    return 0;
}
