#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    while(v.size()>0){
        cout<<v.size()<<endl;
        int min = *min_element(v.begin(), v.end());
        for(auto it = v.begin(); it!=v.end();){
            if(*it==min) v.erase(it);
            else it++;
        }
    }

}