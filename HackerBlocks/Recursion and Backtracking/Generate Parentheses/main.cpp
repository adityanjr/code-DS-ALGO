#include<bits/stdc++.h>
using namespace std;

void generateparentheses(string str,int n, int openbrackets, int closingbrackets){
    if(closingbrackets==n){
        cout<<str<<endl;
        return;
    }
    else{

        if(closingbrackets < openbrackets){
             str.push_back(')');
             generateparentheses(str,n,openbrackets,closingbrackets+1);
             str.pop_back();
         }

         if(openbrackets < n){
             str.push_back('(');
             generateparentheses(str,n,openbrackets+1,closingbrackets);

         }


    }
}
int main(){
    int n;
    cin>>n;
    string str;
    generateparentheses(str,n,0,0);
}
