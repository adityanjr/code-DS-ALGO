/*
    Reference: @see https://leetcode.com/problems/prison-cells-after-n-days/discuss/717443/c%2B%2B-simple-video-explanation
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> prev_cells = cells;
        int n = (int)cells.size();
        N = N % 14 == 0 ? 14 : N % 14; // Pattern repeats in cycle of 14
        
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j == 0 || j == n - 1) {
                    cells[j] = 0;
                    continue;
                }
                
                cells[j] = prev_cells[j - 1] == prev_cells[j + 1] ? 1 : 0;
            }
            prev_cells = cells;
        }
        
        return cells;
    }
};