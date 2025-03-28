#include <stdio.h>
int history[17] = {0};

int check_sum(int arr[16][2],int n) {
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        if(i+arr[i][0]>n){
            history[i] = history[i+1];
            continue;
        }
        int tmep = arr[i][1] + history[i+arr[i][0]];
        history[i] = history[i+1] > tmep ? history[i+1] : tmep;
        //printf("%d history %d = currunt money %d + history[%d] = %d\n",i,history[i],arr[i][1],i+arr[i][0],history[i+arr[i][0]]);

        if(sum < history[i]){
            sum = history[i];
        }

    }
    return sum;
}
int main() {
    int n;
    int sum = 0;
    int arr[16][2] = {0};

    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    sum = check_sum(arr,n);
    printf("%d\n",sum);

    for(int i=0; i<n; i++) { 
        printf("%d ",history[i]);
    }

    return 0;

}