#include <stdio.h>

void merge(int arr[], int left, int mid, int right) 
{
    int i = left;//index for left subarray
    int j = mid + 1;//index for right subarray
    int k = 0;//index for temporary array
    
    //temporary array
    int temp[100];

//megre the two halves into temp
    while (i <= mid && j <= right) 
	{
        if (arr[i] < arr[j])
		{
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }


//copy remaining elements of left half(if any)
    while (i <= mid)
	{
        temp[k++] = arr[i++];
    }

//copy remaining elements of right half(if any)
    while (j <= right)
	{
        temp[k++] = arr[j++];
    }


//copy sorted elements back into original array
    for (i = left, k = 0; i <= right; i++, k++)
	{
        arr[i] = temp[k];
    }
}

void mergesort(int arr[], int left, int right) 
{
    if (left < right)
	{
        int mid = (left + right) / 2;

//sort the two halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        
        
//the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() 
{
    int arr[100], n,i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    
//call merge sort 
    mergesort(arr, 0, n - 1);

//print sorted array;
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

