class dsu{
	public:
	vector<int> arr;
	dsu(int n):arr(n){
		for(int i=0;i<n;i++){
			arr[i]=i;
		}
	}

	void merge(int a, int b){
		arr[find(arr[a])]=arr[find(arr[b])];
	}

	int find(int x){
		if(arr[x]!=x){
			arr[x]=find(arr[x]);
		}
		return arr[x];
	}
};

class Solution {

public:
	int largestComponentSize(vector<int>& A) {
		int n=*max_element(A.begin(),A.end());
		dsu DSU(n+1);
		for(auto x:A){
			int temp=sqrt(x);
			for(int k=2;k<=temp;k++){
				if(x%k==0){
					DSU.merge(x,k);
					DSU.merge(x,x/k);
				}
			}
		}
		unordered_map<int,int> m;
		int res=1;
		for(auto v:A){
			m[DSU.find(v)]+=1;
			res=max(res,m[DSU.find(v)]);
		}
		return res;
	}
};