class Solution {
public:
    int N;
    unordered_map<int, int> buyMap;
    unordered_map<int, int> sellMap;
    
    int maxProfit(vector<int>& prices) {
        N = prices.size();
        return buy(prices, 0);
    }
    
    int buy(vector<int>& prices, int i) {
        if(i >= N) return 0;
        if(buyMap.find(i) != buyMap.end()) return buyMap[i];
        
        int val = max(-prices[i] + sell(prices, i + 1), buy(prices, i + 1));
        
        buyMap[i] = val;
        
        return buyMap[i];
    }
    
    int sell(vector<int>& prices, int i) {
        if(i >= N) return 0;
        if(sellMap.find(i) != sellMap.end()) return sellMap[i];
        
        int val = max(prices[i] + buy(prices, i + 2), sell(prices, i + 1));
        
        sellMap[i] = val;
        
        return sellMap[i];
    }
};