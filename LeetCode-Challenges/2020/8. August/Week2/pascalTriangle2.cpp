class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> prev;
        prev.push_back(1);
        
        vector<int> res(prev);
        
        for(int i = 1; i <= k; ++i) {
            res.clear();
            res.push_back(1);
            
            for(int p = 0; p < prev.size() - 1; ++p) {
                res.push_back(prev.at(p) + prev.at(p + 1));
            }
            
            res.push_back(1);
            
            prev = res;
        }
        
        return res;
    }
};