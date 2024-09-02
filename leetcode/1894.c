int chalkReplacer(int* chalk, int chalkSize, int k) {
    int cnt=0;
    long sum = 0;
    for(int i=0;i<chalkSize;i++)
    {
        sum+=chalk[i];

    }

    k = k%sum;
    while(1)
    {
        k = k-chalk[cnt];

        if(k<0)
        {
            return cnt;
        }
        cnt++;
        if(cnt == chalkSize)
        {
            cnt =0;
        }

    }
    
}