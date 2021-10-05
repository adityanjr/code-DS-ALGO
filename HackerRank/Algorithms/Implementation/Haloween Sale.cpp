#include <iostream>
using namespace std;
int main(){
    int p,d,m,s;
    cin>>p>>d>>m>>s;

    int count=0;
    while(s>=p){
        count++;
        s-=p;
        p = (p - d) >= m ? p-d : m;
    }
    cout<<count;
}