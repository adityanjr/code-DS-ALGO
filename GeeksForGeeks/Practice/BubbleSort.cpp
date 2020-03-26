/* The task is to complete bubble() which is used 
   in below bubbleSort() */

/* A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   for (int i = 0; i < n-1; i++)      
        bubble(arr, i, n);
} */

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble(int arr[], int i, int n)
{
    // Your code here  
    for(int j = n-1; j > i; j--){
        if(arr[j] < arr[i]){
            swap(arr[j], arr[i]);
        }
    }
}
