/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


int maxlength( string s)
{
    // your code here
    int n = s.size(), i = 0, ans = 0, temp = 0;
    
    while(i < n){
        if(s[i] == '0'){
            temp = 0;
        }
        else{
            temp++;
        }
        
        ans = max(ans, temp);
        i++;
    }
    
    return ans;
}
