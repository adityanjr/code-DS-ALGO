#include <iostream>
using namespace std;

int main(){
    int s,t,a,b,m,n;
    cin>>s>>t>>a>>b>>m>>n;
    int* apples = new int[m];
    int* oranges = new int[n];

    for(int i=0; i<m; i++){
        cin>>apples[i];
    }
    for(int i=0; i<n; i++){
        cin>>oranges[i];
    }
    int countApples = 0;
    int countOranges = 0;

    for(int i=0; i<m; i++){
        int fall = a + apples[i];
        if(fall>=s && fall<=t){
            countApples++;
        }
    }
    for(int i=0; i<n; i++){
        int fall = b + oranges[i];
        if(fall>=s && fall<=t){
            countOranges++;
        }
    }
    cout<<countApples<<endl;
    cout<<countOranges<<endl;
}
