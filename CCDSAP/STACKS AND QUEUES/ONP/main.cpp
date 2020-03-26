#include <bits/stdc++.h>
using namespace std;

int precedence(char s){
    if(s=='+')
         return 1;
    else if(s=='-')
        return 2;
    else if(s=='*')
        return 3;
    else if(s=='/')
        return 4;
    else if(s=='^')
        return 5;
    else
         return 6;
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        char s[410];
        cin>>s;

        string ss;
        stack<char>s1;

        for(int i=0;i<strlen(s);i++){
            if(s[i] == '('){
                s1.push('(');
            }

            else if(s[i]==')'){
                while(s1.top()!='('){ // I was stuck here, i also wrote s1.empty(), but it is not needed here.
                        ss.push_back(s1.top());
                        s1.pop();
                }
                s1.pop();
            }

            else if(s[i]=='+' || s[i]=='-' || s[i]=='/'|| s[i]=='*' || s[i]=='^'){

                if(s1.empty()){
                    s1.push(s[i]);

                }
                else{
                  while((precedence(s[i])>precedence(s1.top())) && !s1.empty()){ // precedence should be like if 3>1 then it means that *>+ and we have
                                                                                 // pop out elements unless we found operator which has greater or equal precedence
                        ss.push_back(s1.top());
                        s1.pop();
                    }
                    s1.push(s[i]);
                }
            }
            else{
                ss.push_back(s[i]);
            }
        }

        while(!s1.empty()){
            ss.push_back(s1.top());
            s1.pop();
        }
        cout<<ss<<endl;
    }
    return 0;
}
