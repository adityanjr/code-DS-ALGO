#include<iostream>
using namespace std;

bool staircase(int a[][30], int R, int C, int key){
    int i=0, j=C-1;
    while(i<R && j>=0){
        if(a[i][j]==key)
            return true;
        else if(a[i][j]>key)
            j--;
        else
            i++;
    }
    return false;
}
int main() {
    int r,c, x;
    cin>>r>>c;
    int a[30][30];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a[i][j];
        }
    }
    cin>>x;
    bool Y=staircase(a,r,c,x);
    cout<<Y;
	return 0;
}