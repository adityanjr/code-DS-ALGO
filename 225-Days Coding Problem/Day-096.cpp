class Solution {
    bitset<100>visited;
    vector<vector<int>>res;
    int n; 
    void generatePermutation(vector<int>& nums , vector<int>&temp){
        if((int)temp.size() == n){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<n;++i){
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                generatePermutation(nums , temp);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = (int)nums.size();
        visited.reset();
        vector<int>temp;
        generatePermutation(nums, temp);
        return res;
    }
};

