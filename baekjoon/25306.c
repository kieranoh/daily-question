#include <stdio.h>

long long mod_4(long long a) {
    if(a %4==0) return a;
    else if(a%4 == 1) return 1;
    else if(a%4 == 2) return a+1;
    else return 0;

}

int main(){
 long long a,b;
 scanf("%lld %lld",&a, &b);
 printf("%lld",mod_4(a-1)^mod_4(b));
}