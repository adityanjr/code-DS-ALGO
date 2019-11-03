#include<iostream>
#include<bitset>
using namespace std;
bitset<30> col,d1,d2;
void solve(int r,int n,int &ans){
    if(r==n){
        ans++;
        return;
    }
    for(int c=0;c<n;c++){
        if( !col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c] = d1[r-c+n-1] = d2[r+c] = 1;
            solve(r+1,n,ans);
            col[c] = d1[r-c+n-1] = d2[r+c] = 0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int ans = 0;
    solve(0,n,ans);
    cout<<ans<<endl;
return 0;
}

///to print all configs..

#include<iostream>
#include<bitset>
using namespace std;

bitset<30> col,d1,d2;
int board[15][15] = {0};


void printboard(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void solve(int r,int n,int &ans){
    if(r==n){ ans++; printboard(n); return; }
    for(int c=0;c<n;c++){
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){

            col[c] = d1[r-c+n-1] = d2[r+c] = board[r][c] = 1;
            solve(r+1,n,ans);
            col[c] = d1[r-c+n-1] = d2[r+c] = board[r][c] = 0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    solve(0,n,ans);
    cout<<ans<<endl;

}