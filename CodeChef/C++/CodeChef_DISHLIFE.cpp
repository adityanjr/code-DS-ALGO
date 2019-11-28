#include <bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		int n,k,m,x,sf=0,sflag=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			sf = 0;
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				if(s.find(x)!=s.end())
					sf++;
				s.insert(x);
			}
			if(sf == m)
				sflag = 1;
		}

		if(s.size()!=k)
			printf("sad\n");
		else if(sflag==1)
			printf("some\n");
		else
			printf("all\n");
	}
	return 0;
}