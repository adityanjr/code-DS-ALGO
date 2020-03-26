int transitionPoint(int arr[],int n)
{
    if(n == 1){
        if(arr[0] == 1){
            return 0;
        }
        return 1;
    }
    
    int start = 0, end = n-1, ans = 0;
    
    if(arr[start] == arr[end]){
        if(arr[start] == 0){
            return n;
        }       
        return 0;
    }
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(start + 1 == end){
            if(arr[start] == arr[end]){
                if(arr[start] == 0){
                    return end+1;
                }
                else{
                    return start;
                }
            }
            else{
                return end;
            }
        }
        else if(arr[mid] == arr[start]){
            start = mid;
        }
        else if(arr[mid] = arr[end]){
            end = mid;
        }
    }
    
    return ans;
}
