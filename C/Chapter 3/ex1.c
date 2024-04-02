#include <stdio.h>
int binarysearch(int arr[], int n, int x)
{
    int low = 0,high = n-1,mid = (low+high)/2;
    while (low<high && x != arr[mid])
	{
        if (x>arr[mid])
            low = mid+1;
        else
            high = mid-1;
		mid = (low+high)/2;
    }
    if (x == arr[mid])
        return mid;
    return -1;
}
int main()
{
	int n,x;
	printf("Enter the array size: ");
	scanf("%d",&n);
    int arr[n];
	printf("Enter the array elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to be searched: ");
	scanf("%d",&x);
	printf("Element found at the position: %d\n",binarysearch(arr,n,x));
    return 0;
}
