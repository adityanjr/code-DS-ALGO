#include<bits/stdc++.h>
using namespace std;
set<string>sets;
int main() {
    string s;
    cin>>s;
    string copy = s;
    sort(copy.begin(),copy.end());
    while(next_permutation(copy.begin(),copy.end())){
        if(copy>s){
            sets.insert(copy);
        }
    }
    set<string>::iterator itr;
    for(itr = sets.begin();itr!= sets.end(); itr++){
        cout<<*itr<<endl;
    }
	return 0;
}
