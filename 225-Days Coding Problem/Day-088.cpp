class Solution {
    public:
    int divide(int dividend, int divisor) {
        int sign = ( dividend < 0 ) ^ (divisor < 0) ? -1 : 1;
        if(dividend == numeric_limits<int>::min()){
            if(divisor == 1){
                return dividend;
            }else if(divisor == -1){
                return numeric_limits<int>::max();
            }
        }
        divisor  = (divisor > 0) ? -divisor :  divisor;
        dividend =  (dividend > 0) ? -dividend : dividend;
        int best_quotient = 0, temp=1 , quotient = divisor;
        while(quotient >=INT_MIN>>1 and dividend <= quotient + quotient){
            quotient += quotient;
            temp <<= 1;
        }
        while(dividend <= divisor) {
            if(dividend <= quotient) {
                dividend -= quotient;
                best_quotient += temp;
            }
            quotient >>=1;
            cout << quotient << '\n'; 
            temp >>= 1;
        }
        return sign < 0 ? -best_quotient : best_quotient;
    }
};

