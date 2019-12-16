#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
int main() {

    ll N,t,x,sum=0;
    cin>>t;

    while(t--){
        cin>>N;
		ll arr[N];
        memset(arr,0,sizeof(arr));
        arr[0]=1;
        sum=0;
        for(int i=0;i<N;i++){
            cin>>x;
            sum+=x;
            sum %= N;
			sum = (sum + N)%N;
			arr[sum]++;
        }
        ll result = 0;
        for(int i =0;i<N;i++){
               result += (arr[i]*(arr[i]-1))/2;
        }
        cout<<result<<endl;
    }
	return 0;
}
