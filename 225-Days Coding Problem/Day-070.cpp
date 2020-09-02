class Solution{
    public:
        int getNextPerfectNumber(int n){
            auto temp_sum = 0;
            auto temp = n;
            while(n){
                temp_sum += (n%10);
                n /= 10;
            }
            return temp*10+(10 - temp_sum);
        }
};
