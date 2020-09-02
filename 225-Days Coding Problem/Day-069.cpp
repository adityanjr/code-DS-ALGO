class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 , max2 , max3;
        int min1 , min2; 
        max1 = max2 = max3 = numeric_limits<int>::min();
        min1 = min2 = numeric_limits<int>::max();
        for(auto&itr:nums){
            if(itr>=max1){
                max3 = max2;
                max2 = max1;
                max1 = itr;
            }else if(itr>=max2){
                max3 = max2;
                max2 = itr;
            }else if(itr>=max3){
                max3 = itr;
            }
            if(itr<=min1){
                min2 = min1;
                min1 = itr;
            }else if(itr<=min2){
                min2 = itr;
            }
        }
        return std::max({max1*max2*max3 , min1*min2*max1});
    }
};
