class Solution{
    private:
        int rand5(void)const noexcept{
            srand(time(NULL));
            return rand()%5+1;
        }
    public:
        int rand7(void)noexcept{
            int generatedNumber = -1;
            while(true){
                generatedNumber = (rand5()-1)*5+rand5();
                if(generatedNumber<=21){
                    return generatedNumber%7+1;
                }
            }
        }
};
