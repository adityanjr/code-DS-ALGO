/*

FAST FIBONACCI
Fibonacci series is well-known series in which in which each number (Fibonacci number) is the sum of the two preceding numbers. The series looks like 1, 1, 2, 3, 5, 8…. and so on. Your task is to find nth number.
Since the number can be large, output the answer modulo (109+7).

Input Format:
An integer T, denoting the number of test cases. Each test case contains and integer N.

Constraints:
1<=T<=10^5 1<=N<=10^9

Output Format
Print the nth Fibonacci number modulo (109+7).

Sample Input
4
3
4
5
6
Sample Output
2
3
5
8

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k=2;
#define MOD 1000000007

vector<vector<ll>> multiply(vector<vector<ll>>A,vector<vector<ll>>B){
    vector<vector<ll>>X(k+1,vector<ll>(k+1));
    for(ll i =1;i<=k;i++){
        for(ll j=1;j<=k;j++){
            for(ll l=1;l<=k;l++){
                X[i][j] =( X[i][j] + (A[i][l]*B[l][j])%MOD)%MOD;
            }
        }
    }
    return X;
}


vector<vector<ll>> power(vector<vector<ll>>T, ll n){
    if(n==1)
       return T;

     vector<vector<ll>>X = power(T,n/2);
     X = multiply(X,X);

     if(n&1)
        return multiply(X,T);

      return X;
}

ll compute(ll n){
    if(n==1 || n==2)
       return 1;
    else {

        vector<ll>F1(k+1);

        for(ll i=1;i<=k;i++){
            F1[i]=1;
        }

        vector<vector<ll>>T(k+1,vector<ll>(k+1));

        for(ll i=1;i<=k;i++){
            for(ll j=1;j<=k;j++){
             if(i<k){
                if(i==j-1){
                    T[i][j]=1;
                }
                else{
                    T[i][j]=0;
                 }
              }
              else{
                  T[i][j]=1;
              }
            }
          }

           T = power(T,n-1);

           ll val = 0;

           for(ll i=1;i<=k;i++){
               val = (val + (T[1][i] * F1[i])%MOD)%MOD;
           }
           return val;
        }
    }


int main(){
    ll t,n;

    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n;
        cout<<compute(n)<<endl;
    }

    return 0;
}
