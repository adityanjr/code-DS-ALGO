//  https://www.interviewbit.com/problems/n-max-pair-combinations/

vector<int> A;
vector<int> B;


#define pii pair<int,int>
vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    A=a;
    B=b;
    vector<int>ans;
    int n=A.size();
    if(n==0)return ans;
    
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    
    priority_queue<pair<int,pii>,vector<pair<int,pii>>> pq;
    pq.push({A[0]+B[0],{0,0}});
    map<pii,bool>mp;
    mp[{0,0}]=true;
    while(ans.size()<n){
        pair<int,pii> p=pq.top();
        pq.pop();
        int l=p.second.first;
        int r=p.second.second;
        ans.push_back(p.first);
        if(r+1<n and mp[{l,r+1}]==false)mp[{l,r+1}]=true,pq.push({A[l]+B[r+1],{l,r+1}});
        if(l+1<n and mp[{l+1,r}]==false)mp[{l+1,r}]=true,pq.push({A[l+1]+B[r],{l+1,r}});
    }
    return ans;
}
