class Solution {
public:
    vector<int> total;
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int sum = 0;
        
        for(vector<int> rect: rects) {
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            total.push_back(sum);
        }
    }
    
    vector<int> pick() {
        int maxValue = this->total[this->total.size() - 1];
        int target = (rand() % maxValue);
        
        int hi = total.size(), low = 0, mid;
        
        while(low < hi) {
            mid = low + (hi - low) / 2;
            
            if(total[mid] > target) {
                hi = mid;
            } else {
                low = mid + 1;
            }
        }
        
        vector<int> rect = this->rects[low];
        
        int x1 = rect[0];
        int y1 = rect[1];
        int x2 = rect[2];
        int y2 = rect[3];
        
        int x = (rand() % (x2 - x1 + 1));
        int y = (rand() % (y2 - y1 + 1));
        
        vector<int> pairs {x + x1, y + y1};
        return pairs;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */