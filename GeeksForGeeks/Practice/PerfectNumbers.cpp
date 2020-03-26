#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//code
    int test;
    cin >> test;
    
    while(test--){
        int n, ans = 0, sum = 1;
        cin >> n;
        
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0){
                sum += i;
                if(i != sqrt(n)){
                    sum += n/i;
                }
            }
        }
        
        if(sum == n && n != 1){
            ans = 1;
        }
        
        cout << ans << endl;
    }
	
	return 0;
}
