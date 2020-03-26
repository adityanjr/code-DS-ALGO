/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*you are required to complete this method*/
int convertFive(int n)
{
//Your code here
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            s[i] = '5';
        }
    }
    
    return stoi(s);
}
