#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v3d vector<vector<vector<ll>>>
#define v2d vector<vector<ll>>
#define v1d vector<ll>
int r,n,q;
int matrix[100005][3][3];
v3d tree(400020,v2d(3,v1d(3)));

v2d multiply(v2d &a,v2d &b){ // Make a multiply Function.
    v2d c(3,v1d(3));
     for(ll int j=1;j<=2;j++){
	        for(ll int k=1;k<=2;k++){
	            ll int sum=0;
	            for(ll int i=1;i<=2;i++){
	                sum+=a[j][i]*b[i][k];

	            }
	            c[j][k]=sum%r;
	        }
	  }
	  return c;
}

void buildtree(int ss, int se, int index){
    if(ss==se){
         for(int j=1;j<=2;j++){
	        for(int k=1;k<=2;k++){
	            tree[index][j][k]= matrix[ss][j][k];
	        }
	    }
        return;
    }

    int mid = ss + (se-ss)/2;
    buildtree(ss,mid,2*index);
    buildtree(mid+1,se,2*index+1);

    tree[index]=multiply(tree[2*index],tree[2*index+1]);
    return;
}

v2d query(ll ss, ll se, ll l, ll r, ll index){
  if(l>se || r<ss){
      v2d identity(3,v1d(3)); // declare 2d vector like vector<vector<int>>v(3,vector<int>)
      return identity;
  }


  if(ss>=l && se<=r){
      return tree[index];
  }

  int mid = ss + (se-ss)/2;
  v2d mat;
  v2d mat1;

  if(r<=mid){
    return query(ss,mid,l,r,2*index);
  }
  if(l>mid){
    return query(mid+1,se,l,r,2*index+1);
  }

  mat = query(ss,mid,l,r,2*index);
  mat1 = query(mid+1,se,l,r,2*index+1);

  return multiply(mat,mat1);

}
int main() {

    cin>>r>>n>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++)
              cin>>matrix[i][j][k];
        }
    }

    buildtree(1,n,1);
    v2d temp;
    int x,y;
    while(q--){
        cin>>x>>y;
        temp = query(1,n,x,y,1);
        for(int i=1;i<=2;i++){
          for(int j=1;j<=2;j++)
                cout<<temp[i][j]<<" ";
             cout<<endl;
        }
        cout<<endl;
        temp.clear();
      }

    return 0;
}
