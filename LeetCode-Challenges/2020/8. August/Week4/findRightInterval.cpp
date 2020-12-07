class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        vector<int> result;
        int n = intervals.size();
        
        if(n == 0) return {};
        if(n == 1) return {-1};
        
        for(int i = 0; i < n; ++i) {
            int start = intervals[i][0];
            m[start] = i;
        }
        
        for(int i = 0; i < n; ++i) {
            int end = intervals[i][1];
            auto it = m.lower_bound(end);
            
            int index = it != m.end() ? it -> second : -1;
            result.push_back(index);
        }
        
        return result;
    }
};