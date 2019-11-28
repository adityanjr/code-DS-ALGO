#include<bits/stdc++.h>
using namespace std;
string temp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,d,p=0;
    double attendance=0;
    cin>>t;
    int proxy;
    for(int m=0;m<t;m++){

    cin>>d>>temp;
    string s = temp;
    proxy = 0;

    for(int i=0;i<d;i++){
        if(s[i]=='P')
            p++;
    }

    attendance = p/d;
    int i = 2 ;
    while(attendance<0.75 && i<(d-2)){
        if(s[i]=='A'){
            if((s[i-1]=='P' || s[i-2]=='P') && (s[i+1]=='P' || s[i+2]=='P')){
                    p++;
                    s[i]='P';
                    proxy++;
                }
            }
        attendance = p/d;
        i++;
    }

    if(attendance>=0.75)
        cout<<proxy<<endl;
    else
       cout<<"-1"<<endl;
    }
    return 0;
}
