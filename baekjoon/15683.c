#include <stdio.h>
#include <string.h>

int map[9][9] = {0};
int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int num =0;
int cctv_map[8][3] = {0};
int min = 9999999;

void copyMap(int src[9][9], int dst[9][9]){
    for (int i = 0; i < n; i++){
        memcpy(dst[i], src[i], sizeof(int) * m);
    }
}

void print_map(){
    printf("-------------\n");
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void move (int x_pos, int y_pos,int d){
    int temp_x = x_pos + dx[d];
    int temp_y = y_pos + dy[d];
    while(temp_x >=0 && temp_x <m && temp_y >=0 && temp_y < n )
    {
        if(map[temp_y][temp_x] == 6) break;
        if(map[temp_y][temp_x]==0) map[temp_y][temp_x] = -1;
        
        temp_x += dx[d];
        temp_y += dy[d];
    }
}

void move_back (int x_pos, int y_pos,int d){
    int temp_x = x_pos + dx[d];
    int temp_y = y_pos + dy[d];
    while(temp_x >=0 && temp_x <m && temp_y >=0 && temp_y < n )
    {
        if(map[temp_y][temp_x] == 6) break;
        if(map[temp_y][temp_x]==-1) map[temp_y][temp_x] = 0;
        
        temp_x += dx[d];
        temp_y += dy[d];
    }
}

void cctv_1(int x_pos, int y_pos,int d){
    move(x_pos,y_pos,d);
}

void cctv_1_back(int x_pos, int y_pos,int d){
    move_back(x_pos,y_pos,d);
}

void cctv_2 (int x_pos, int y_pos,int d){ 
    move(x_pos,y_pos,d);
    d = (d+2)%4;
    move(x_pos,y_pos,d);
}

void cctv_2_back(int x_pos, int y_pos,int d){ 
    move_back(x_pos,y_pos,d);
    d = (d+2)%4;
    move_back(x_pos,y_pos,d);
}

void cctv_3 (int x_pos, int y_pos,int d){ 
    move(x_pos,y_pos,d);
    d = (d+1)%4;
    move(x_pos,y_pos,d);
}

void cctv_3_back(int x_pos, int y_pos,int d){ 
    move_back(x_pos,y_pos,d);
    d = (d+1)%4;
    move_back(x_pos,y_pos,d);
}

void cctv_4 (int x_pos, int y_pos,int d){ 
    move(x_pos,y_pos,d);
    d = (d+1)%4;
    move(x_pos,y_pos,d);
    d = (d+1)%4;
    move(x_pos,y_pos,d);
}

void cctv_4_back(int x_pos, int y_pos,int d){ 
    move_back(x_pos,y_pos,d);
    d = (d+1)%4;
    move_back(x_pos,y_pos,d);
    d = (d+1)%4;
    move_back(x_pos,y_pos,d);
}

void cctv_5 (int x_pos, int y_pos){ 
    for(int i=0; i<4;i++){
        move(x_pos,y_pos,i);
    }
}

void cctv_5_back(int x_pos, int y_pos){ 
    for(int i=0; i<4;i++){
        move_back(x_pos,y_pos,i);
    }
}

void find_min(int cnt){
    if(cnt == num){
        int result = 0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(map[i][j]==0) result ++;
            }
        }
        //print_map();
        // if(min > result){
        //     print_map();
        // }
        min = min> result ? result : min;
        return;
    }
    int backup[9][9];
    copyMap(map, backup);

    if(cctv_map[cnt][2]==1){
        for(int i=0; i<4;i++){
            copyMap(backup,map);
            cctv_1(cctv_map[cnt][1],cctv_map[cnt][0],i);
            find_min(cnt+1);
            

        }
    }
    else if(cctv_map[cnt][2]==2){
        for(int i=0; i<2;i++){
            copyMap(backup,map);
            cctv_2(cctv_map[cnt][1],cctv_map[cnt][0],i);
            find_min(cnt+1);

        }
    }
    else if(cctv_map[cnt][2]==3){
        for(int i=0; i<4;i++){
            copyMap(backup,map);
            cctv_3(cctv_map[cnt][1],cctv_map[cnt][0],i);
            find_min(cnt+1);

        }
    }
    else if(cctv_map[cnt][2]==4){
        for(int i=0; i<4;i++){
            copyMap(backup,map);
            cctv_4(cctv_map[cnt][1],cctv_map[cnt][0],i);
            find_min(cnt+1);

        }
    }
    
    
}




int main(){
    scanf("%d %d",&n,&m);

    for(int i = 0; i<n; i++){
        for(int j=0; j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    //print_map();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==5){
                cctv_5(j,i);
            }
            else if(map[i][j]!=6 && map[i][j]!=0&& map[i][j]!=-1) {
                cctv_map[num][0] = i;
                cctv_map[num][1] = j;
                cctv_map[num][2] = map[i][j];
                num++;
            }
        }
    }
    find_min(0);

    printf("%d",min);
    
}