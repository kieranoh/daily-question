#include <stdio.h>
#include<string.h>

long long max = -1000000000;
long long min = 1000000000;
int cal[4] = {0};
int input[12] = {0};
int n;
void check(int idx, long long num){
    long long temp;
    if(idx>=n){
        //printf("max %d min %d num %d\n",max,min,num);
        max = max < num ? num : max;
        min = min > num ? num : min;
        return;
    }

    for(int i=0;i<4;i++){
        if(cal[i]==0){
            continue;
        }
        if(i==0) {
            //printf("%d + %d\n",num, input[idx]);
            temp = num +  input[idx];

            cal[i]--;
            check(idx+1,temp);

            cal[i]++;
        }
        if(i==1) {
            temp = num - input [idx];
            //printf("%d - %d\n",num, input[idx]);
            cal[i]--;
            check(idx+1,temp);
            cal[i]++;
        }if(i==2) {
            //printf("%d * %d\n",num, input[idx]);
            temp = num *  input[idx];
            cal[i]--;
            check(idx+1,temp);
            cal[i]++;
        }
        if(i==3) {
            
            //printf("%d / %d\n",num, input[idx]);
            temp = num / input[idx];
            cal[i]--;
            check(idx+1,temp);
            cal[i]++;
        }
    }
}

int main() {
    scanf("%d",&n);

    for(int i=0; i<n;i++) {
        scanf("%d",&input[i]);
    }


    for(int i=0; i<4;i++){
        scanf("%d",&cal[i]);
    }
    check(1,input[0]);

    printf("%lld\n",max);
    printf("%lld",min);


}