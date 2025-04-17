#include <stdio.h>
#include <stdlib.h>

typedef struct shark
{
    int speed;
    int d;
    int size;
}shark;

shark map[101][101];

shark temp_map[101][101];

int r,c;

void print_map(){
    printf("--------------\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf(" %d ",map[i][j].size);
        }
        printf("\n");
    }
}

void init_map(shark target[101][101]) {
    for(int i=0; i<r;i++){
        for(int j=0; j<c; j++){
            target[i][j].d = -1;
            target[i][j].size = -1;
            target[i][j].speed = -1;
        }
    }
}

void copy_map (shark from[101][101], shark to[101][101]) {
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            to[i][j].d = from[i][j].d;
            to[i][j].size = from[i][j].size;
            to[i][j].speed = from[i][j].speed;
        }
    }
}


void move() {
    init_map(temp_map);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j].d == -1) continue;
            int s = map[i][j].speed;
            int d = map[i][j].d;
            int sz = map[i][j].size;
            int nr = i, nc = j;

            if (d == 0 || d == 1)     
                s %= (2 * (r - 1));
            else                      
                s %= (2 * (c - 1));


            for (int step = 0; step < s; step++) {
                int di = (d == 0 ? -1 : (d == 1 ? 1 : 0));
                int dj = (d == 2 ? 1  : (d == 3 ? -1 : 0));


                if (nr + di < 0 || nr + di >= r) {
                    d = (d == 0 ? 1 : 0);
                    di = (d == 0 ? -1 : 1);
                }
                if (nc + dj < 0 || nc + dj >= c) {
                    d = (d == 2 ? 3 : 2);
                    dj = (d == 2 ? 1 : -1);
                }

                nr += di;
                nc += dj;
            }
            if (temp_map[nr][nc].d == -1 || temp_map[nr][nc].size < sz) {
                temp_map[nr][nc].d = d;
                temp_map[nr][nc].speed = map[i][j].speed;
                temp_map[nr][nc].size  = sz;
            }
        }
    }

    copy_map(temp_map, map);
}

int get(int idx){
    for(int i=0; i<r;i++){
        if(map[i][idx].d != -1)
        {
            int result = map[i][idx].size;
            map[i][idx].d = -1;
            map[i][idx].size = -1;
            map[i][idx].speed = -1;
            return result;
        }
    }
    return 0;
}

int cal(){
    int result = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j].size!=-1){
                result+=map[i][j].size;
            }
        }
    }
    return result;
}

int main() {

    int num_s;
    scanf("%d %d %d",&r, &c, &num_s);

    init_map(map);

    for(int i=0; i<num_s;i++) {
        int temp_r, temp_c, temp_speed,temp_d,temp_size;
        scanf("%d %d %d %d %d",&temp_r, &temp_c, &temp_speed,&temp_d,&temp_size);
        temp_c = temp_c-1;
        temp_r = temp_r-1;
        map[temp_r][temp_c].d = temp_d-1;
        map[temp_r][temp_c].size = temp_size;
        map[temp_r][temp_c].speed = temp_speed;
    }
    //print_map();

    int result = 0;

    for(int i=0; i<c;i++){
        result+=get(i);
        move();
       // printf("%d\n",i);
        //print_map();
    }

 

    printf("%d\n",result);

    return 0;
}