/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


int maxlength( string s)
{
// your code here
    int temp = 0, ans = 0, i = 0, n = s.size();
    
    while(i < n){
        if(s[i] == '1'){
            temp++;
        }
        else{
            temp = 0;
        }
        ans = max(ans, temp);
        i++;
    }
    
    return ans;
}
