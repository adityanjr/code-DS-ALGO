#include<bits/stdc++.h>
using namespace std;
int N,Q;

void buildSegmentTree(int *arr, int ss, int se, int *tree, int index){

	if(ss==se){
		tree[index]=arr[ss];
		return;
	}

	int mid = ss + (se-ss)/2;
    buildSegmentTree(arr,ss,mid,tree,2*index);
	buildSegmentTree(arr,mid+1,se,tree,2*index+1);

	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}

void updateTree(int *tree,int ss, int se, int index, int value, int position){

   if(ss>position || se<position){
	   return;
   }

   if(ss==se){
	   tree[index] = value;
	   return;
   }

   int mid = ss + (se-ss)/2;
   updateTree(tree,ss,mid,2*index,value,position);
   updateTree(tree,mid+1,se,2*index+1,value,position);

   tree[index] = min(tree[2*index],tree[2*index+1]);
   return;
}

int query(int *tree,int ss, int se, int l, int r, int index){

	if(l<=ss && r>=se){
        return tree[index];
	}

	if(ss>r || se<l){
		return INT_MAX;
	}


	int mid = ss + (se - ss)/2;

	int leftval = query(tree,ss,mid,l,r,2*index);
	int rightval = query(tree,mid+1,se,l,r,2*index+1);

	return min(leftval,rightval);
}

int main() {

	cin>>N>>Q;
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}

	int *tree = new int[4*N+1];

	buildSegmentTree(arr,0,N-1,tree,1);

	while(Q--){
		int L,R,C;
		cin>>C>>L>>R;
		if(C==1){
            cout<<query(tree,0,N-1,L,R,1)<<endl;
		}

		else {
			updateTree(tree,0,N-1,1,R,L);
		}
	}
	return 0;
}
