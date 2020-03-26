#include<iostream>
using namespace std;
int main() {
    
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0; i<n ;i++){
        for(int j=0; j< m ;j++){
            cin >> a[i][j];
        }
    }
    
    int sr=0,sc=0;
    
    while( sr < n && sc < m){
        
        //printing first columns from the remaining columns
        for(int i=sr;i<n;i++){
            cout << a[i][sc] << ", ";
        }
        sc++;
        
        //printing last row from the remaining rows
        for(int i=sc;i<m;i++){
            cout << a[n-1][i] << ", ";
        }
        n--;
        
        //printing last clomuns from the remaining columns
        if(sc<m){
        
            for(int i=n-1 ;i>=sr ; i-- ){
                cout << a[i][m-1] << ", ";
            }
            m--;
        }
        // printing first row of the remaining rows
        
        if(sr<n){
            
            for(int i = m-1; i>=sc ; i--){
                cout << a[sr][i] << ", " ;
            }
            sr++;
        }
    }
    
    
    
    cout << "END" << endl;
	return 0;
}