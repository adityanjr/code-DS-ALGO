#include<bits/stdc++.h>
using namespace std;
set<vector<int>>s;

void sumItUp(int arr[],vector<int>v,int n, int t,int sum, int pos){
	if(sum==t){
         s.insert(v);
		 return;
	}

	for(int i=pos;i<n;i++){
		if(arr[i]==t){
			vector<int>temp;
			temp.push_back(arr[i]);
			s.insert(temp);
		}
        sum += arr[i];
		if(sum>t){
			sum-=arr[i];
		}
	   else{
         v.push_back(arr[i]);
		 sumItUp(arr,v,n,t,sum,i+1);
		 v.pop_back();
		 sum-=arr[i];
	   }

	}
}

int main() {
	int t,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
           cin>>arr[i];
    cin>>t;
	sort(arr,arr+n);
    vector<int>v;
	sumItUp(arr,v,n,t,0,0);
    set<vector<int>>::iterator itr;
    for(itr = s.begin();itr!=s.end();itr++){
        vector<int>v1 = *itr;
        for(int i=0;i<v1.size();i++)
            cout<<v1[i]<<" ";
        cout<<endl;
    }
}

/*        Previous Solution
#include<bits/stdc++.h>
using namespace std;
set<vector<int>>s;
int main() {
	int t,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
           cin>>arr[i];
    cin>>t;
    sort(arr,arr+n);
    do{
        int sum = 0;
        vector<int>v;
        for(int i =0;i<n;i++){
            sum+=arr[i];
               if(sum==t){
                for(int j=0;j<=i;j++){
                    v.push_back(arr[j]);
                }
                    sort(v.begin(),v.end());
                    s.insert(v);
                    v.clear();
                    break;
           }
        }
    }while(next_permutation(arr,arr+n));
    set<vector<int>>::iterator itr;

    for(itr = s.begin();itr!=s.end();itr++){
        vector<int>v1 = *itr;
        for(int i=0;i<v1.size();i++)
            cout<<v1[i]<<" ";
        cout<<endl;
    }
}
*/
