#include <iostream>
using namespace std;

int main(){

    int b, n, m;
    cin>>b>>n>>m;
    int board[n], drive[m];
    for(int i=0; i<n; i++){
        cin>>board[i];
    }
    for(int i=0; i<m; i++){
        cin>>drive[i];
    }
    int max =-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i]+drive[j]>max && board[i]+drive[j]<=b){
                max = board[i]+drive[j];
            }
        }
    }
    cout<<max;
}