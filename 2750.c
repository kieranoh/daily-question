#include <stdio.h>
void quick_sort(int *arr,int L,int R)
{
	int left = L;
	int right = R;
	int p = arr[(L+R)/2]; //pivot 설정 (가운데 기준값)
	int temp;//swap 용 temp

	do
	{
		while(arr[left]<p)
		{
			left++;
		}
		while(arr[right]>p)
		{
			right--;
		}
		if(left<=right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;			
		}
	}while(left<=right);
	
	if(L<right)
	{
		quick_sort(arr,L,right);
	}
	if(left<R)
	{
		quick_sort(arr,left,R);
	}
}

int main()
{
    int num,temp;
    scanf("%d",&num);

    int arr[1000];

    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,num-1);

    for(int i=0;i<num;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
    

}