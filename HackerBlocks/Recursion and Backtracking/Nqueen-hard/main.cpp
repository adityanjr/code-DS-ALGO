// Thanks Competitive Programming 3
#include<bits/stdc++.h>
using namespace std;
bitset<30> col,d1,d2;

void solve(int row, int n, int &ans){
    if(row==n){
        ans++;
        return;
    }

    for(int i=0;i<n;i++){
        if(!col[i] && !d1[row+i] && !d2[row-i+n-1]){
            col[i]=d1[row+i]=d2[row-i+n-1]=1;
            solve(row+1,n,ans);
            col[i]=d1[row+i]=d2[row-i+n-1]=0;
        }

    }
}

int main() {
    int n;
    cin>>n;
    int ans = 0;
    solve(0,n,ans);
    cout<<ans<<endl;
	return 0;
}
