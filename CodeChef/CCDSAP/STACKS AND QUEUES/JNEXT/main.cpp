#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
int main() {

   int t;
   cin>>t;
   while(t--){
   	 int n;
   	 cin>>n;

   	 vector<int>vec(n);
   	 for(int i=0;i<n;i++) cin>>vec[i];
   	 int i = n-1;
   	 while(i>0 && vec[i-1]>=vec[i]) i--;

   	 if(i<=0) {cout<<-1<<endl; continue;}

   	 int j=n-1;

   	 while(vec[j] <= vec[i-1]) --j;

   	 swap(vec[i-1],vec[j]);
   	 sort(vec.begin()+i,vec.end());

   	 for(int i=0;i<n;i++) cout<<vec[i];
     cout<<endl;
   }
	return 0;
}
