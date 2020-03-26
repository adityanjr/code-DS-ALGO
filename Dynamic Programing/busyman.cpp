#include <bits/stdc++.h>
#include<vector>

using namespace std;

bool cmp(pair<int, int>left,pair<int, int>right ){

	return left.second<right.second;

}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector<pair<int, int> > activities;

		while(n--){
			int start, end;
			cin>>start>>end;
			activities.push_back(make_pair(start,end));
		}

		sort(activities.begin(), activities.end(),cmp);

		pair<int, int> curr_act = activities[0];
		int count =1;
		for (int i = 1; i < activities.size() ; i++)
		{	
			//cout<<activities[i].first<<" "<<activities[i].second<<endl;

			if(curr_act.second<=activities[i].first){
				count++;
				curr_act = activities[i];
			}

		}

		cout<<count<<endl;

	}
	return 0;
}







