#include <stdio.h>
#include <conio.h>

int main()
{
    int n, value, pos, m = 0, arr[100], choice;
    printf("Enter the total elements in the array:  ");
    scanf("%d", &n);

    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search:  ");
    scanf("%d", &value);

    printf("Choose the type of search,\n 1 for Linear Search, \n 2 for Binary Search\n");
    printf("choice = ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        pos = linearSearch(arr, value, 0, n);
         if (pos != 0)
        {
         printf("Element found at pos %d ", pos);
        }
       else
       {
        printf("Element not found");
       }
    }
    else
    {
        bubbleSort(arr, n);
        printf("\n");
        binarySearch(arr, 0, n, value);
    }

    return 0;
}
int linearSearch(int arr[], int value, int index, int n)
{
    int pos = 0;

    if(index >= n)
    {
        return 0;
    }

    else if (arr[index] == value)
    {
        pos = index + 1;
        return pos;
    }

    else
    {
        return linearSearch(arr, value, index+1, n);
    }
    return pos;
}


void bubbleSort(int arr[], int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void binarySearch(int arr[], int l, int h, int value)
{
    int mid;

    if (l > h)
    {
        printf("Element not found\n");
        return;
    }
    mid = (l + h) / 2;
    if (arr[mid] == value)
    {
        printf("Element found at pos %d",mid+1);
    }
    else if (arr[mid] > value)
    {
        binarySearch(arr, l, mid - 1, value);
    }
    else if (arr[mid] < value)
    {
        binarySearch(arr, mid + 1, h, value);
    }
}
