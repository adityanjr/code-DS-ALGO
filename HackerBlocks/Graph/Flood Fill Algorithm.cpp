#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void floodfill(int mat[][],int i, int j, char curr, char color){
     if(i<0 || j<0 || i>=R || j>=C)
       return;
    
    if(mat[i][j]!=curr)
        return;
    
    mat[i][j] = color;
    for(int k = 0;k<4;k++){
        floodfill(mat,i+dx[k],j+dy[k],'.','R');
    }
}

int main() {
    int R,C;
    cin>>R>>C;
    int position[R][C];
    
    for(int i = 0;i<R;i++){
        for(int j = 0 ;j<C;j++){
                 cin>>position[i][j];
        }
    }
    
    floodfill(position,8,13,'.','R');
    
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            cout<<position[i][j];
        }
        cout<<endl;
    }
}
