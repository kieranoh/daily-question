
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int result = 0; 
    int cnt = 0;
    for(int i=0; i<wordsSize;i++)
    {
        
        for(int j=0;j<strlen(words[i]);j++)
        {
            cnt = 0;
            for(int k=0; k<strlen(allowed);k++)
            {
                if(words[i][j] == allowed[k])
                {
                    cnt++;
                }
            }
            if(cnt<1)
            {
                result++;
                break;
            }
        }
    }
    return wordsSize - result; 
}