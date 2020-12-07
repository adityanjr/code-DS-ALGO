/*
    O(N) Time and Space
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> map;

        for(int num: nums)
            map[num]++;

        for(auto &x: map)
            if(x.second > 1)
                res.push_back(x.first);

        return res;
    }
}

/*
    Without Extra Space
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(int i = 0; i < n; ++i) {
            int curr = abs(nums[i]);
            
            nums[curr - 1] = -1 * nums[curr - 1];
            
            if(nums[curr - 1] > 0) res.push_back(curr);
        }
        
        return res;
    }
};