#include<iostream>
#include <algorithm>
using namespace std;
void permute(char*in,int i,int &k,string temp[]) {
    //base case
    if(in[i]=='\0') {
        temp[k]=in;
        k++;
        return;
    }   
    for(int j=i;in[j]!='\0';j++) {
        if(!(j!=i && in[i]==in[j])){
            swap(in[i],in[j]);
            permute(in,i+1,k,temp);
            swap(in[i],in[j]);
        }
    }    
}
int main() {
	char c[100];
	cin>>c;
	string temp[100000];
	int k=0;
	permute(c,0,k,temp);
    string s[100000];
    int r=0;
	for(int i=0;i<k;i++){
	    int flag=0;
	    for(int j=i+1;j<k;j++) {
	        if(temp[i]==temp[j])
	            flag=1;
	    }
	    if(flag==0) {
	        s[r]=temp[i];
	        r++;
	    }
	}
	sort(s,s+r);
    for(int i=0;i<r;i++)
        cout<<s[i]<<endl;
}
