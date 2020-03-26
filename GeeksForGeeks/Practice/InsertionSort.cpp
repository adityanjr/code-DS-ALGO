/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The task is to complete insert() which is used 
   as shown below to implement insertionSort() */
/* Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++)
      insert(arr, i);
} */
void shuffle(int arr[], int i, int k){
    int temp = arr[i], tempk = k;
    
    for(int j = i; j > k; j--){
        arr[j] = arr[j-1];
    }
    
    arr[tempk] = temp;
}

void insert(int arr[], int i)
{
    // Your code here  
    for(int k = 0; k < i; k++){
        if(arr[i] < arr[k]){
            shuffle(arr, i, k);
            return;
        }
    }
}
