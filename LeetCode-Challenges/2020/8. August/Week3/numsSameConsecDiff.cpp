class Solution {
    void dfs(int K, int currentNumber, int digitsLeft, vector<int>& res) {
        if(digitsLeft == 0) {
            res.push_back(currentNumber);
            return;
        }
        
        int lastDigit = currentNumber % 10;
        
        if((lastDigit + K) <= 9) {
            dfs(K, (currentNumber * 10) + lastDigit + K, digitsLeft - 1, res);
        }
        
        if((lastDigit - K) >= 0 && K != 0) {
            dfs(K, (currentNumber * 10) + lastDigit - K, digitsLeft - 1, res);
        }
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        
        if(N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for(int i = 1; i < 10; ++i) {
            dfs(K, i, N - 1, res);   
        }
        
        return res;
    }
};