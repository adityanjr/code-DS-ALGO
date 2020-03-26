#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string str;
	int t;
	int a,b,c,d,e,f;
	cin >> n;
	int arr[n];

	for(i=0;i<n;i++)
		cin >> arr[i];

	for(a=0;a<n-5;a++)
	{
		for(b=a+1;b<n-4;b++)
		{
			for(c=b+1;c<n-3;c++)
			{
				for(d=c+1;d<n-2;d++)
				{
					for(e=d+1;e<n-1;e++)
					{
						for(f=e+1;f<n;f++)
						{
							cout << arr[a] << " " << arr[b] << " " << arr[c] << " " << arr[d] << " " << arr[e] << " " << arr[f] << endl;
						}
					}
				}
			}
		}
	}



	return 0;
}
