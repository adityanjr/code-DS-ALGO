class Solution{
    private:
        int counter{};
    public:
        int getAppearingValue( int n , int x ) {
            counter = 0;
            for(int i=1; i<=n and i<=sqrt(x);++i){
                if(!(x%i)){
                    counter+=(x/i <= n);
                    counter+=(x/i!=i and x/i<=n and i<=n);
                }
            }
            return counter;
        }
};
