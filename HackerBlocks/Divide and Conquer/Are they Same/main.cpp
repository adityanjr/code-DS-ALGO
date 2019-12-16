#include <bits/stdc++.h>
using namespace std;
string s1,s2;

bool merge(int start, int mid, int end){

	 string s3 = s1.substr(start,mid);
	 string s4 = s1.substr(mid+1,end);
	 string s5 = s2.substr(start,mid);
	 string s6 = s2.substr(mid+1,end);

	 if((s3==s6 && s4==s5) || (s3==s5 && s4==s6))
	   return true;

	 return false;
}

bool mergesort(int l , int r){
	if(l<r){
		int mid = l + (r-l)/2;
        return mergesort(0,mid) && mergesort(mid+1,r) && merge(l,mid,r);
	}
}

int main()
{  int t;

	cin>>t;
  while(t--){
	cin>>s1;
	cin>>s2;
	if(s1==s2){
		cout<<"YES"<<endl;
		break;
	}

	else{
		bool success = mergesort(0,s1.length()-1);

		if(success)
		  cout<<"YES"<<endl;
		else
		  cout<<"NO"<<endl;
	}

  }
    return 0;
}
