// http://www.geeksforgeeks.org/given-a-number-n-generate-bit-patterns-from-0-to-2n-1-so-that-successive-patterns-differ-by-one-bit/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void generateGray(int n){
    vector<string> v;
    v.pb("0");
    v.pb("1");
    for(int i=2; i<(1<<n); i=i<<1){
        //copy in rev order
        for(int j=i-1; j>=0; j--){
            v.pb(v[j]);
        }
        for(int j=0; j<i; j++){
            v[j] = '0'+v[j];
            v[i+j] = '1'+v[i+j];
        }
    }
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<'\n';
}

int main() {
    int n=2;
    generateGray(n);    // 0 -> (2^n)-1
	return 0;
}

