/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the element of the array is as
struct Height {
	int feet;
	int inches;
};
*/
// function must return the maximum Height
// return the height in inches
int findMax(Height arr[], int n)
{
    // Code here
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans = max(ans, arr[i].feet*12 + arr[i].inches);
    }
    
    return ans;
}
