#include <iostream>
using namespace std;
int main()
{
    int q;
    cin>>q;
    long long int a,b,c;
    int remainder = 0;
    while(q--){
        remainder = 0;
        cin>>a>>b>>c;
        if(a&1){
            a--;
            remainder++;
            }

        if(b&1){
            b--;
            remainder++;
            }

      if(c&1){
            c--;
            remainder++;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        cout<<a+b+c+(remainder/2)<<endl;

    }

    return 0;
}
