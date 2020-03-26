#include <iostream>

using namespace std;

int hcf(int a, int b){
    if(a == 0){
        return b;
    }
    return hcf(b%a, a);
}


int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int s1, s2, n, ans = 0;
	    cin >> s1 >> s2 >> n;
	    
	   // int lcm = (int)((long int)(s1*s2))/(hcf(s1, s2));
	   // int total = lcm/s1 + lcm/s2;
	    
	   // if(n/total){
    // 	    ans = (n%total + n/total)*lcm;
    // 	    n = n%total;
	   // }
	    
	   // cout << lcm << endl;
	    
	    int t1 = s1, t2 = s2;
	    
	    while(n > 0){
	        int mini = min(t1, t2);
	        ans += mini;
	        t1 -= mini;
	        t2 -= mini;
	       // cout << "n : " << n << endl;
	       // cout << "t1 : " << t1 << " t2 : " << t2 << endl;
	       // cout << "ans : " << ans << endl;
	        if(t1 == 0){
	           // cout << "t1 = s1, s1 = " << s1 << endl;
	            t1 = s1;
	            n--;
	        }
	        if(t2 == 0){
	           // cout << "t2 = s2, s2 = " << s2 << endl;
	            t2 = s2;
	            n--;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
