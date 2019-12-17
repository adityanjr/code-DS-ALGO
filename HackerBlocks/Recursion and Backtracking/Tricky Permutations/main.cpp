#include<bits/stdc++.h>
using namespace std;
vector<string>v;

void trickyPermutations(string str, int len,string s){
    if(s.size()==len){
        vector<string>::iterator itr;
        itr = find(v.begin(),v.end(),s);
        if(itr==v.end()){
            v.push_back(s);
        }
        return;
    }
    string alreadydone;
    for(int i=0;i<str.size();i++){
          if(alreadydone.find(str[i])!=string::npos){
              continue;
          }
        alreadydone.push_back(str[i]);
        s.push_back(str[i]);
        string temp;
        temp.push_back(str[i]);
        str.erase(str.begin()+i);
        trickyPermutations(str,len,s);
        s.pop_back();
        str.insert(i,temp);
        temp.clear();
          }
    }
int main() {
    string str;
    cin>>str;
    string s;
    trickyPermutations(str,str.size(),s);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
	return 0;
}

/* Better approach

#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    int val = str.size();
    sort(str.begin(),str.end());
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(),str.end()));
	return 0;
}


*/

