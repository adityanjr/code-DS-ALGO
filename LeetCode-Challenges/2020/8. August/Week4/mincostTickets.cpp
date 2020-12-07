class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size() - 1];
        bool travelDays[n + 1];
        int dp[n + 1];
        
        fill(travelDays, travelDays + n + 1, false);
        fill(dp, dp + n + 1, 0);
        
        for(int day: days) {
            travelDays[day] = true;
        }
        
        for(int i = 1; i < n + 1; ++i) {
            if(!travelDays[i]) {
                dp[i] = dp[i - 1];
                continue;
            }
            
            int one = dp[i - 1] + costs[0];
            int seven = dp[max(i - 7, 0)] + costs[1];
            int thirty = dp[max(i - 30, 0)] + costs[2];
            
            dp[i] = min(one, min(seven, thirty));
        }
        
        return dp[n];
    }
};