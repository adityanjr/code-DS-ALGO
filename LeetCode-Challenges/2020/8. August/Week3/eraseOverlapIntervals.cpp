class Solution {
public:
    static bool compare(vector<int> L1, vector<int> L2) {
        return L1[0] < L2[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        
        if(n == 0 || n == 1) return 0;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int prevEnd = intervals[0][1];
        
        for(int i = 1; i < n; ++i) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            if(prevEnd <= currentStart) {
                prevEnd = currentEnd;
            } else if(prevEnd > currentStart && prevEnd >= currentEnd) {
                count++;
                prevEnd = currentEnd;
            } else {
                count++;
            }
        }
        
        return count;
    }
};