class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
        {
            return true;
        }
        int i=1;
        long l=1,r=num;
        long  mid =(l+r)/2;
        while(r>=l)
        {
            if(mid*mid==num)
            {
                return true;
            }
            if(mid*mid>num)
            {
                r=mid-1;
                mid =(l+r)/2;
            }
            else
            {
                l=mid+1;
                mid =(l+r)/2;
            }
        }
        return false;

    }
};
