#include <stdio.h>
#include <string.h>

int main(){
    int room_num;
    int main_t, sub_t;
    long long result=0;

    scanf("%d",&room_num);

    int* room_people = (int*)malloc(room_num*sizeof(int));

    for(int i=0; i<room_num;i++){
        scanf("%d",&room_people[i]);
    }

    scanf("%d %d",&main_t,&sub_t);

    result = room_num;

    for(int i=0; i<room_num;i++){
        int temp = room_people[i] - main_t;
        if(temp <=0) continue;;

        result +=temp/sub_t;
        if(temp%sub_t !=0) result++;

    }

    printf("%lld",result);

    return 0;


}