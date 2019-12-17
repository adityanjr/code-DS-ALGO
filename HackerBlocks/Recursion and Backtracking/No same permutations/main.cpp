#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int str[n];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>str[i];
    sort(str,str+n);
    do{
       for(int i=0;i<n;i++)
          cout<<str[i]<<" ";
        cout<<endl;
    }while(next_permutation(str,str+n));
	return 0;
}
