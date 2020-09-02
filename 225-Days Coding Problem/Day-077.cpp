class Solution {
    static bool compare(vector<int>&a , vector<int>&b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , compare);
        vector<vector<int>>res;
        int n = static_cast<int>(intervals.size());
        for(int i=0;i<n;++i){
            int current_min_start = intervals[i][0];
            int current_largest_end = intervals[i][1];
            while(i+1<n && current_largest_end>=intervals[i+1][0]){
                current_largest_end = max(intervals[i+1][1] , current_largest_end);
                current_min_start = min(intervals[i+1][0] , current_min_start);
                ++i;
            }
            res.push_back({current_min_start , current_largest_end});
        }
        return res;
    }
};

