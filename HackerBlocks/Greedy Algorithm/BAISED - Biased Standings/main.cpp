#include <iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        int arr[n+1]={0};
        int val;
        for(int i=1;i<=n;i++){
            cin>>s>>val;
            arr[val]++;
        }

        long long int ans = 0;
        long long int j = 1;
        for(int i=1;i<=n;i++){
            while(arr[i]!=0){
                ans += abs(i-j);
                j++;
                arr[i]--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
