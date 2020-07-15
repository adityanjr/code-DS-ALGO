class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)==true)
        {
            return 1;
        }
        long long int left=1;
        long long int right =n;
        long long  mid=(left+right)/2;
        while(right>=left)
        {
            int ValMid=isBadVersion(mid);
           // int Val
            if(mid!=1 && isBadVersion(mid-1)==false && ValMid==true)
            {
                return mid;
            }
            if(ValMid==false)
            {
                left=mid+1;
                mid= (left+right)/2;
            }
            if(ValMid==true)
            {
                right=mid-1;
                mid=(left+right)/2;
            }
        }
        return n;
    }
};
