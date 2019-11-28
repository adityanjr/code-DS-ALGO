#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int answer[n];
        for(int i=0;i<n;i++){
            cin>>answer[i];
            answer[i] *= 20;
        }
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            temp *=10;
            answer[i] = answer[i] - temp;
            if(answer[i]<0)
                answer[i]=0;
        }
        cout<<*max_element(answer,answer+n)<<endl;
    }
    return 0;
}
