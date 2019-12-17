#include<bits/stdc++.h>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void smartKeypad(string str, int len, int pos, string s){
    if(len==pos){
        cout<<s<<endl;
        return;
    }

    int index = str[pos] - '0';
    string temp = table[index];

    for(int i=0;i<temp.size();i++){
        s.push_back(temp[i]);
        smartKeypad(str,len,pos+1,s);
        s.pop_back();
    }

}
int main() {
   string str;
   string s;
   cin>>str;
   smartKeypad(str,str.size(),0,s);
}
