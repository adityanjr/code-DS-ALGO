class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n == 0 || n == 1) return 0;
        
        int left[n];
        int right[n];
        
        left[0] = 0;
        right[n - 1] = 0;
        
        int minLeft = prices[0];
        for(int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], prices[i] - minLeft);
            minLeft = min(minLeft, prices[i]);
        }
        
        int maxRight = prices[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], maxRight - prices[i]);
            maxRight = max(maxRight, prices[i]);
        }
        
        int maxProfit = 0;
        
        for(int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }
        
        return maxProfit;
    }
};