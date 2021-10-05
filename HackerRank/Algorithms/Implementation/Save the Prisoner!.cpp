#include <iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m, s;
        cin>>n>>m>>s;
        int rem = m%n; //if starts from 1
        int ans = (rem+s-1)%n;
        if(ans==0){
            cout<< n<<endl;
        }
        else {
            cout<<ans<<endl;
        }
    }
    return 0;
}