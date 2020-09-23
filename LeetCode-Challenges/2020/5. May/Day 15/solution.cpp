class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        //used Kadane's Algorithm
        int max_sub=INT_MIN,max_end=0;
        int min_sub=INT_MAX,min_end=0;
        int total=0,Max=INT_MIN;
        for(int i=0;i<A.size();i++)
        {
           // max sub array
            max_end=max_end+A[i];
            max_end=max(max_end,0);
            max_sub=max(max_sub,max_end);

            Max=max(Max,A[i]);

          // min sub array
            min_end=min_end+A[i];
            min_end=min(min_end,0);
             min_sub=min(min_sub,min_end);

           total=total+A[i];
        }
        if(Max<0)
        {
            return Max;
        }
        // finding maximum of normal array and circular array (taking 2 cases)
        //refer to hint 3
        return max(max_sub,total-min_sub);
    }
};
