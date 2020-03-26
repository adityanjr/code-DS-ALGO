#include <iostream>
#include <string>

using namespace std;

int getDig(int n, int sum){
    if(n == 1 || sum == 0){
        return sum;
    }
    else if(sum/n == 9 && sum%n != 0){
        return -1;
    }
    else{
        if(sum-9 >= 0){
            return 9;
        }
        else if(sum-8 >= 0){
            return 8;
        }
        else if(sum-7 >= 0){
            return 7;
        }
        else if(sum-6 >= 0){
            return 6;
        }
        else if(sum-5 >= 0){
            return 5;
        }
        else if(sum-4 >= 0){
            return 4;
        }
        else if(sum-3 >= 0){
            return 3;
        }
        else if(sum-2 >= 0){
            return 2;
        }
        else if(sum-1 >= 0){
            return 1;
        }
    }
    return -1;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, sum;
	    cin >> n >> sum;
	    
	    string ans = "";
	    
	    while(n){
	        int digit = getDig(n, sum);
	        if(digit > 9 || digit == -1){
	            ans = "-1";
	            break;
	        }
	        sum = sum - digit;
	        ans = ans + to_string(digit);
	        n--;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
