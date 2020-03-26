/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


void make(char str[], string s, int curr, int n, bool space){
    if(curr == n){
        if(space){
            cout << s << "$";
        }
        return;
    }
    
    make(str, s+str[curr], curr+1, n, space);
    make(str, s+" "+str[curr], curr+1, n, true);
}

/*You have to complete this function*/
void  printSpace(char str[])
{
//Your code here
    cout << str << "$";
    string curr = "";
    curr += str[0];
    make(str, curr, 1, strlen(str), false);
}
