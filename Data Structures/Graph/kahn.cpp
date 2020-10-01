#include<vector>
#include<queue>
#include<iostream>

using namespace std;
typedef long long int lld;

int main()
{
	lld t, i;

	cin >> t;

	for(i = 0; i < t; ++i)
	{
		lld v, e, j, x, y;

		cin >> v >> e;

		vector < vector < lld > > adj(v);
		vector < lld > in(v, 0);
		queue < lld > ans;

		for(j = 0; j < e; ++j)
		{
			cin >> x >> y;

			adj[x].push_back(y);
			++in[y];
		}

		for(j = 0; j < v; ++j)
		{
			if(!in[j])
				ans.push(j);
		}

		while(!ans.empty())
		{
			lld temp = ans.front();
			cout << ans.front() << " ";
			ans.pop();

			for(lld k = 0; k < adj[temp].size(); ++k)
			{
				--in[adj[temp][k]];
				
				if(!in[adj[temp][k]])
					ans.push(adj[temp][k]);
			}
		}

		cout << endl;
	}

	return 0;
}
