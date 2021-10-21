#include<bits/stdc++.h>
using namespace std;

//here , we may change 0 to 1 up to k values

//find the longest subarray with atmost k zeros
//for each a[j] , find longest subarray
//if a[i] - a[j] has zeros <=k , continue j++;  // expanding window
//if a[i] - a[j] has zeros >k , continue i++, j++   // contacting window

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a)
    cin>>i;
    int zero_cnt = 0;
    int i=0;
    int ans= 0;
    for(int j=0;j<n;j++){
        if(a[j]==0)
        zero_cnt++;

        while(zero_cnt>k)
        {
            if(a[i]==0){
                zero_cnt--;
            }

            i++;
        }
        //zero_cnt<=k
        ans = max(ans,j-i+1);

    }

    cout<<ans<<endl;

    return 0;
}