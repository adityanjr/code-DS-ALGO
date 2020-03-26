#include <iostream>

using namespace std;

int main()
{
	//code
    int test;
    cin >> test;
    
    while(test--){
        int n;
        cin >> n;
        
        cout << n*n*n + n << endl;
    }
    
	return 0;
}
