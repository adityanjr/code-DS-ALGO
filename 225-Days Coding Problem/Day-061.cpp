/*
This problem was asked by Google.

Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

class Solution {
public:
    double myPow(double x, long long n) {
        double ans =1.0f;
        if(n>0){
            while(n){
                //double a =1;
                if(n&1){
                    ans*=x;   
                }
                x*=x;
                n>>=1;
            }
        }else{
            n = abs(n);
            while(n){
                if(n&1){
                    ans/=x;
                }
                x*=x;
                n>>=1;
                cout<<n<<endl;
            }
        }
        return ans;
    }
};
