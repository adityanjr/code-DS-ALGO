#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int x; cin>>x; while(x--)
#define f(x,y)          for(int i=x; i<=y; i++)


void c_p_c(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int gcd(int a,int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int arrGCD(int arr[], int n){
    int result = arr[0];
    for (int i=1; i<n; i++){
        result = gcd(arr[i], result);
  
        if(result == 1){
           return 1;
        }
    }
    return result;
}

int main(){
	c_p_c();

	t(x){
		int n; cin>>n;
		mk(arr,n);
		f(0,n-1){
			cin>>arr[i];
		}
		int factor = arrGCD(arr,n);
		f(0,n-1){
			arr[i] = arr[i]/factor;
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}