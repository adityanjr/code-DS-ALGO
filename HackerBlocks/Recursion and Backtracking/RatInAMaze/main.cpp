#include <bits/stdc++.h>
using namespace std;

bool ratInAMaze(char maze[1001][1001],bool path[1001][1001], int n, int m,int i, int j){
    if(i==n-1 && j==m-1){
        path[i][j]=1;
        return true;
    }

   if(maze[i][j]=='X')
     return false;

   if(i>=n || j>=m){
       return false;
   }

   path[i][j]=1;

   bool rightsucess = ratInAMaze(maze,path,n,m,i,j+1);
   if(!rightsucess){
       bool downsucess = ratInAMaze(maze,path,n,m,i+1,j);
       if(!downsucess){
            path[i][j]=0;
            return false;
       }
   }

   return true;

}
int main() {
   int n,m;
   cin>>n>>m;
   char maze[1001][1001];
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>maze[i][j];
       }
   }
   bool path[1001][1001]={0};
   bool sucess = ratInAMaze(maze,path,n,m,0,0);

   if(sucess){
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                cout<<path[i][j]<<" ";
           }
           cout<<endl;
       }

   }
   else
     cout<<-1;
   return 0;
}
