#include<iostream>
using namespace std;
int calc_numbers(int n){
    if(n==1)
	    return 2;
    else if(n==2)
	    return 3;
    else
        return calc_numbers(n-1)+calc_numbers(n-2);
}
int main(){
    int t, n, i=1;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<"#"<<i<<" : "<<calc_numbers(n)<<endl;
	i++;
    }
}

//Optimised

#include<iostream>
using namespace std;

int count_Binary(int n){
    int a[n+1],b[n+1];
    a[0]=0,a[1]=1;
    b[0]=0,b[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }
    return a[n]+b[n];
}

int main(){
    int t, n, i=1;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<"#"<<i<<" : "<<count_Binary(n)<<endl;
	i++;
    }
}