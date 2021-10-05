#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if (a == 0 || b == 0)
        return 0;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

long long int lcm(long long int n1, long long int n2){
    return (n1*n2)/gcd(n1,n2);

}
int getTotalX(vector<int> a, vector<int> b) {
    
    int nA = a.size();
    int lcmA = a[0];
    
    for(int i = 1 ; i < nA ; i++)
        lcmA = lcm(lcmA,a[i]);
    
    int nB = b.size();
    int gcdB = b[0];
    
    for(int i = 1 ; i < nB ; i++)
        gcdB = gcd(gcdB,b[i]);
    
    int count = 0;
    int i = 1;
    int n = 0;
    while( n < gcdB )
    {
        n = lcmA*i;
        if( gcdB % n == 0 )
            count++;
        i++;
    }
    
    return count;
}
int main(){

    int n, m;
    cin>>n>>m;

    vector<int> a;
    vector<int> b;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x; cin>>x;
        b.push_back(x);
    }
    
    cout<<getTotalX(a,b);
}