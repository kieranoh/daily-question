#include <stdio.h>

void merge(int a[], int low, int mid, int hight)   
{
	int b[1000000];
	int i = low;        
	int j = mid + 1;    
	int k = 0;          
	
	while(i <= mid && j <= hight)
	{
		if(a[i] <= a[j])        
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= mid)            
		b[k++] = a[i++];
	while(j <= hight)           
		b[k++] = a[j++];
	k--;
    
	while(k >= 0)               
	{
		a[low + k] = b[k];
		k--;
	}
}
void mergeSort(int a[], int low, int hight)    
{
	
	int mid;
	if(low < hight)
	{
		mid = (low + hight) / 2;
		mergeSort(a, low, mid);            
		mergeSort(a, mid + 1, hight);      
		merge(a, low, mid, hight);          
	}
}
int main(void)
{
	int arr[1000000];
	int i, cnt;        
	
	scanf("%d", &cnt);
	
	for(i = 0 ; i < cnt; i++)
		scanf("%d", &arr[i]);
    
	mergeSort(arr, 0, cnt - 1);    
	
    for(i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
}