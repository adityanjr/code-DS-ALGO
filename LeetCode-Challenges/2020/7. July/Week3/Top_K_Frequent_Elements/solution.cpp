class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> q;
        vector<int> answer;
        
        if((int) nums.size() == k) return nums;
        
        for(int num: nums) {
            freq[num]++;
        }
        
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            q.push(make_pair(it->second, it->first)); 
        }
        
        while(k-- > 0) {
            pair<int, int> val = q.top();
            q.pop();
            
            answer.push_back(val.second);
        }
        
        return answer;
    }
};