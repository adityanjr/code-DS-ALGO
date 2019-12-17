#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	int t,n;
    cin>>t;
    string arr[90];
    arr[0]='2';
    int carry =0;
    for(int i=1;i<90;i++){
        string temp = arr[i-1];
        int sizeoftemp = temp.size();
        carry=0;
        string ans;
        for(int j=sizeoftemp-1;j>=0;j--){
            int val = temp[j] - '0';
            val = (val*2 + carry);
            ans.push_back(val%10+48);
            carry = val/10;
        }
        if(carry>0)
            ans.push_back(carry+48);
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        arr[i] = ans;
        ans.clear();
    }
	    while(t--){
		cin>>n;
		cout<<arr[n-1]<<endl;
	}
	return 0;
}
