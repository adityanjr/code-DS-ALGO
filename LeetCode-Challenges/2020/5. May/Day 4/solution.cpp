class Solution {
public:
    int findComplement(int num) {
        int val=0,i=0;
        while(num/2!=0)
        {
            if(num%2==0)
            {
                val=val+pow(2,i);
            }
            i++;
            num=num/2;
        }
        return val;
    }
};
