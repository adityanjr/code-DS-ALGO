class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        int last = 0;
        vector<int> result(2, 0);
        
        for(int num: nums) {
            r ^= num;
        }
        
        last = r & (~(r - 1));
        
        for(int num: nums) {
            if((num & last) != 0) result[0] ^= num;
            else result[1] ^= num;
        }
        
        return result;
    }
};