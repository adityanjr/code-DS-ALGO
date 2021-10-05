#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int altitude=0;
    int count =0;
    for(int i=0; i<n; i++){
        if(s[i] == 'U'){
            altitude++;
            if(altitude == 0){
                count++;
            }
        }
        else {
            altitude--;
        }
    }
    cout<<count;
}
