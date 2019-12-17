#include <bits/stdc++.h>
using namespace std;
void buildtree(int *arr, int ss,int se, int *tree, int index){

    if(se==ss){ //Leaf node
        tree[index] = arr[se];
        return;
    }

    //Recursive Case
    int mid = ss + (se-ss)/2;
    buildtree(arr,ss,mid,tree,2*index);
    buildtree(arr,mid+1,se,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void update(int ss, int se, int node, int *tree, int increment,int index){
     if(ss>node || se<node){
        return;
     }

     if(ss==se){
        tree[index]+=increment;
        return;
     }

    int mid = ss + (se-ss)/2;
    update(ss,mid,node,tree,increment,2*index);
    update(mid+1,se,node,tree,increment,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);

}

int query(int *tree, int ss, int se, int l, int r, int index){
   if(ss>=l && se<=r){  // If node lies completely between the query then it is COMPLETE OVERLAP.
       return tree[index];
   }

   if(ss>r || se<l){  // No overlap case.
       return INT_MAX;
   }

   // Partial overlap

   int mid = ss +(se-ss)/2;
   int leftans = query(tree,ss,mid,l,r,2*index);
   int rightans = query(tree,mid+1,se,l,r,2*index+1);

   return min(leftans,rightans);

}

void updaterange(int *tree, int ss, int se, int l, int r,int increment, int index){

    if(l>se || r<ss){
        return;
    }

    if(ss==se){
        tree[index]+=increment;
        return;
    }

   int mid = ss+ (se-ss)/2;
   updaterange(tree,ss,mid,l,r,increment,2*index);
   updaterange(tree,mid+1,se,l,r,increment,2*index+1);

   tree[index]=min(tree[2*index],tree[2*index+1]);
}

int main() {
    int arr[] = {1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(int);

    int *tree = new int[4*n+1]; // because in the worst case the size of tree can be 4n+1;
    buildtree(arr,0,n-1,tree,1);
    // update(0,n-1,0,tree,-8,1);
    updaterange(tree,0,n-1,2,3,10,1);
    int no_of_q = 6;

    while(no_of_q--){
        int l,r;
        cin>>l>>r;
        cout<< query(tree,0,n-1,l,r,1)<<endl;
    }
    return 0;
}
