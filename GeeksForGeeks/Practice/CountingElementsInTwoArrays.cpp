/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

void merge(int arr[], int start, int mid, int end){
    int i = start, j = mid+1, k = 0;
    int ans[end-start+1];
    
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            ans[k] = arr[i];
            i++;
        }
        else{
            ans[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while(i <= mid){
        ans[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= end){
        ans[k] = arr[j];
        j++;
        k++;
    }
    
    k = 0;
    while(start <= end){
        arr[start] = ans[k];
        k++;
        start++;
    }
}

void mergeSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    return merge(arr, start, mid, end);
}

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

int bs(int arr[], int key, int start, int end){
    int ans = -1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] > key){
            end = mid-1;
        }
        else{
            ans = max(ans, mid);
            start = mid+1;
        }
    }
    return ans;
}

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here
    mergeSort(arr2, 0, n-1);
    // printArr(arr2, n);
    for(int i = 0; i < m; i++){
        cout << bs(arr2, arr1[i], 0, n-1)+1 << " ";
    }
}
