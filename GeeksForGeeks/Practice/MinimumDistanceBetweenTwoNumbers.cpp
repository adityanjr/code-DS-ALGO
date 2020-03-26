/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below*/
int minDist(int arr[], int n, int x, int y)
{  
    //add code here.
    int i = 0, ans = -1, xInd = -1, yInd = -1;
    
    while(i < n){
        if(arr[i] == x){
            xInd = i;
        }
        else if(arr[i] == y){
            yInd = i;
        }
        if(xInd != -1 && yInd != -1){
            if(ans == -1){
                ans = abs(xInd - yInd);
            }
            else{
                ans = min(ans, abs(xInd - yInd));
            }
        }
        i++;
    }
    
    return ans;
}
