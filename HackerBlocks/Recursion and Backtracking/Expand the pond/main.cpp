#include <bits/stdc++.h>
using namespace std;
int n,m;
int counter[1000][1000];
bool isVisited[1000][1000];
int maxInCounter = 0;
int maxPondSize = 0;
pair<int,int>pp;
vector<pair<int,int>>v;

bool isValid(int arr[][1000],int x, int y){
    return (x>=0) && (x<n) && (y>=0) && (y<m) && (arr[x][y]==0);
}

bool isValid1(int arr[][1000],int x, int y){
    return (x>=0) && (x<n) && (y>=0) && (y<m) && (arr[x][y]==1) && (isVisited[x][y]==false);
}

void expandThePond(int arr[][1000],int n, int m)
{
    for(int i=0; i< v.size(); i++)
    {
        pair<int,int>p = v[i];
        int x = p.first;
        int y = p.second;

        if(isValid(arr,x-1,y)){
            counter[x-1][y]++;
            if(maxInCounter < counter[x-1][y]){
                maxInCounter = counter[x-1][y];
                pp.first = x-1;
                pp.second = y;
            }
        }

           if(isValid(arr,x+1,y)){
            counter[x+1][y]++;
            if(maxInCounter < counter[x+1][y]){
                maxInCounter = counter[x+1][y];
                pp.first = x+1;
                pp.second = y;
            }
        }

           if(isValid(arr,x,y-1)){
            counter[x][y-1]++;
            if(maxInCounter < counter[x][y-1]){
                maxInCounter = counter[x][y-1];
                pp.first = x;
                pp.second = y-1;
            }
        }


           if(isValid(arr,x,y+1)){
            counter[x][y+1]++;
            if(maxInCounter < counter[x][y+1]){
                maxInCounter = counter[x][y+1];
                pp.first = x;
                pp.second = y+1;
            }
        }
    }

   arr[pp.first][pp.second]=1;
}

void pondSize(int arr[][1000], int x,int y){

      if(!(isValid1(arr,x-1,y)|| isValid1(arr,x+1,y) || isValid1(arr,x,y+1) || isValid1(arr,x,y-1))){
        return;
      }

        if(isValid1(arr,x-1,y)){
           isVisited[x-1][y]=true;
           maxPondSize++;
           pondSize(arr,x-1,y);
        }


           if(isValid1(arr,x+1,y)){
           isVisited[x+1][y]=true;
           maxPondSize++;
           pondSize(arr,x+1,y);
        }


           if(isValid1(arr,x,y+1)){
           isVisited[x][y+1]=true;
           maxPondSize++;
           pondSize(arr,x,y+1);
        }


           if(isValid1(arr,x,y-1)){
           isVisited[x][y-1]=true;
           maxPondSize++;
           pondSize(arr,x,y-1);
        }

}
int main()
{

    cin>>n>>m;
    int arr[1000][1000]={0};
    for(int i=0; i<n; i++)
    {   for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
                v.push_back(make_pair(i,j));
            }
        }
    }

    expandThePond(arr,n,m);
    pondSize(arr,0,0);
    cout<<maxPondSize<<endl;

    return 0;
}
