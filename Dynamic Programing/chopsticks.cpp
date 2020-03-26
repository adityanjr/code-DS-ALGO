#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int n,d;
	cin>>n>>d;
	vector<int> v;

	while(n--){
		int stick;
		cin>>stick;
		v.push_back(stick);
	}

	sort(v.begin(), v.end());
	int pairs =0;
	for (int i = 0; i < v.size()-1;)
	{
		if((v[i+1]-v[i])<= d){
			pairs++;
			i+=2;
		}
		else{
			i++;
		}	
	}

	cout<<pairs<<endl;

	return 0;
}






