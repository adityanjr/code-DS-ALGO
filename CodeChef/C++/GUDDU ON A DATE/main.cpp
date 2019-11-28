#include <iostream>
using namespace std;

#define ll long long
string s;
int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>s;
        ll length = s.length();
        long long sum =0;
        for(int j=0;j<length-1;j++){
            sum+=s[j];
        }
        s[length-1]=(sum%10);
        cout<<s<<endl;
    }
    return 0;
}
