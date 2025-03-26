#include <stdio.h>
#include <string.h>

int main(){

    int n,m;
    int x_pos,y_pos;
    int move_count;
    int dice[6] = {0};

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1}; 

    scanf("%d %d %d %d %d",&n,&m,&y_pos,&x_pos,&move_count);

    int map[20][20] = {0};

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int i=0; i<move_count;i++){
        
        int move;
        scanf("%d",&move);

        int temp_x = x_pos+dx[move-1]; 
        int temp_y = y_pos + dy[move-1];
 
        //check range
        if(temp_x >=m || temp_x <0 || temp_y >=n ||temp_y <0) {
            //printf("ofr\n");
            continue;
        }
        x_pos = temp_x;
        y_pos = temp_y;
        
        //move dice
        if(move==1) {
            int temp = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[3];
            dice[3] = dice[0];
            dice[0] = temp;
        }
        else if(move==2) {
            int temp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
        }
        else if(move==3) {
            int temp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
        }
        else {
            int temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
        }

        if(map[y_pos][x_pos]==0){
            map[y_pos][x_pos]=dice[5];
        }
        else {
            dice[5] = map[y_pos][x_pos];
            map[y_pos][x_pos] = 0;
        }

        printf("%d\n",dice[0]);


    }  

    return 0;
}