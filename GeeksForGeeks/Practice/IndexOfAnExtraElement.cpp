/*Complete the function below*/
int findExtra(int a[],int b[],int n)
{
 //add code here.
    int start = 0, end = n-1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        
        if(mid >= n){
            return n-1;
        }
        if(a[mid] == b[mid]){
            start = mid + 1;
        }
        else{
            if(start + 1 == end){
                if(b[start] != a[start]){
                    return start;
                }    
                return end;
            }
            if(a[mid] == b[mid-1]){
                end = mid-1;
            }
            else{
                return mid;    
            }
        }
    }
    
    return 0;
}
