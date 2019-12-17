#include<bits/stdc++.h>
using namespace std;

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string table[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

void smartKeypad(string str, int len, int pos, string s){
    if(len==pos){
        for(int i=0;i<11;i++){
            if(searchIn[i].find(s)!=string::npos){
                 cout<<searchIn[i]<<endl;
            }
        }
        return;
    }

    int index = str[pos] - '0';
    string temp = table[index-1];

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
