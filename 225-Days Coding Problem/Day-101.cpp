#include <bits/stdc++.h>
using namespace std;
class Solution{
    vector<bool>isPrime;
    void sieve(int n){
        isPrime.assign(n+2 , true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i<=n/2;++i){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        return;
    }
    public:
        vector<int>primeNumber(int n){
            sieve(n);
            for(int i=2;i<=n;++i){
                if(isPrime[i] && n-i>0 && isPrime[n-i]){
                    return {i,n-i};
                }
            }
            assert(false);
        }
};
int main(void){
    Solution s1;
    vector<int> v = s1.primeNumber(4);
    cout << v[0]  <<" "<< v[1] << '\n';
    vector<int> i = s1.primeNumber(99); 
    cout << i[0]  <<" "<< i[1] << '\n';
    return 0;
}
