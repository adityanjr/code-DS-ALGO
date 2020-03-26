/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are requried to complete this method */
int max_Books(int a[], int n, int k)
{
    // Your code here
    int i = 0, ans = 0, temp = 0;
    
    while(i < n){
        if(a[i] <= k){
            temp += a[i];
        }
        else{
            temp = 0;
        }
        ans = max(ans, temp);
        i++;
    }
    
    return ans;
}
