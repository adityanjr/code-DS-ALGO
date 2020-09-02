class Solution {
    unordered_set<int>s;
public:
    int longestConsecutive(vector<int>& nums) {
        for(auto&itr: nums){
            s.insert(itr);
        }
        int best_ans {};
        for(auto&itr:s){
            if(s.find(itr-1)==s.end()){
                int current = itr; 
                int temp_ans = 1;
                while(s.find(current+1)!=s.end()){
                    ++temp_ans;
                    ++current;
                }
                best_ans = max(temp_ans , best_ans);
            }
        }
        return best_ans;
    }
};
