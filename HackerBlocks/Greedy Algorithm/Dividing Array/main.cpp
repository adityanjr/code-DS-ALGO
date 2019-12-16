#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define ll long long int

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr,arr+n);
        ll max_ans = 0;
        ll min_ans = 0;

        for(int i=1;i<n;i+=2){
            min_ans += abs(arr[i-1] - arr[i]);
        }

        int half = n/2;
        for(int i=0;i<half;i++){
            max_ans += abs(arr[i] - arr[i+half]);
        }

        cout<<min_ans<<" "<<max_ans<<endl;
    }
	return 0;
}
