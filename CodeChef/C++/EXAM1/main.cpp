#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,N;
    cin>>T;
    int points=0;
    char s1[105];
    char s2[105];
    while(T--){
        points=0;
        N=0;
        cin>>N;
       for(int i=0;i<N;i++)
              cin>>s1[i];
       for(int i=0;i<N;i++)
              cin>>s2[i];

        for(int i=0;i<N-1;i++){

            if(s2[i]=='N')
                continue;
            else if(s1[i]!=s2[i])
                i=i+1;
            else
                points++;

        }

        if(s1[N-1]==s2[N-1])
                points++;

        cout<<points<<endl;
    }
    return 0;
}
