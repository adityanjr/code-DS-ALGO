#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {

    ll n,t;
    cin>>t;
    while(t--){
        cin >> n;
        ll A[n];
        ll count = 0;
        unordered_map<ll, vector<ll>> hashmap;
        for (ll i = 0; i < n; ++i)
            cin >> A[i];
        hashmap[A[0]].push_back(0);
        for (ll i = 1; i < n; ++i)
        {
            A[i] = A[i] ^ A[i-1];
            if (!A[i]){
                count += i;
            }
            hashmap[A[i]].push_back(i);
        }
        unordered_map<ll, vector<ll>>::iterator i2;

        for (i2 = hashmap.begin(); i2 != hashmap.end(); ++i2)
        {
            ll size = i2->second.size();
            if(size>=2){
            vector<ll>v = i2->second;
            ll sumofsize =  ((size-1)*(2 + (size-2)))/2;
            count -= sumofsize;
            for(ll i=0;i<size;i++){
                count += ((2*i)-size+1)*v[i];
              }
            }
        }
        cout<<count<<endl;
    }
}




/* #include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        int totalxor = 0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            totalxor ^= a[i];
        }
        int count = 0;
        int Xor = 0;
        for(int i=0;i<n-1;i++){
            Xor = a[i];
            for(int j=i+1;j<n;j++){
                Xor ^= a[j];
                if(Xor==0){
                    count+=(j-i);
                }
            }
        }

        cout<<count<<endl;
    }
}
  */
