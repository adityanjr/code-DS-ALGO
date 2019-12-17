#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
public:
    ll maxPrefixsum;
    ll maxSuffixsum;
    ll totalsum;
    ll maxSum;
    node(){
        maxPrefixsum = INT_MIN;
        maxSuffixsum = INT_MIN;
        totalsum = INT_MIN;
        maxSum = INT_MIN;
    }
};

ll n,q;
ll arr[100005];
vector<node>tree(400020);

node initialize(node left, node right){
    node current;
    current.maxPrefixsum = max(left.maxPrefixsum, left.totalsum+right.maxPrefixsum);
    current.maxSuffixsum = max(right.maxSuffixsum, right.totalsum + left.maxSuffixsum);
    current.totalsum = left.totalsum + right.totalsum;
    current.maxSum = max(left.maxSuffixsum + right.maxPrefixsum, max(left.maxSum, right.maxSum));
    return current;
}

void buildtree(ll ss, ll se, ll index){
    if(ss==se){
        tree[index].maxPrefixsum = arr[ss];
        tree[index].maxSuffixsum = arr[ss];
        tree[index].totalsum = arr[ss];
        tree[index].maxSum = arr[ss];
        return;
    }

    ll mid = ss+(se-ss)/2;
    buildtree(ss,mid,2*index);
    buildtree(mid+1,se,2*index+1);

    node current;
    node left = tree[2*index];
    node right = tree[2*index+1];

    current.maxPrefixsum = max(left.maxPrefixsum, left.totalsum+right.maxPrefixsum);
    current.maxSuffixsum = max(right.maxSuffixsum, right.totalsum + left.maxSuffixsum);
    current.totalsum = left.totalsum + right.totalsum;
    current.maxSum = max(left.maxSuffixsum + right.maxPrefixsum, max(left.maxSum, right.maxSum));

    tree[index] = current;

    return;
}

node query(ll ss, ll se, ll l, ll r,ll index){

    if(ss>r || se<l){
         node t;
        return t;
    }

    if(ss>=l && se<=r){
        return tree[index];
    }

    ll mid = ss+ (se-ss)/2;
    node left;
    node right;
    if(r<=mid){
        return query(ss,mid,l,r,2*index);
    }

    left = query(ss,mid,l,r,2*index);
    right = query(mid+1,se,l,r,2*index+1);
    node ans = initialize(left,right);
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    buildtree(0,n-1,1);
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<query(0,n-1,l-1,r-1,1).maxSum<<endl;
    }
    return 0;
}
