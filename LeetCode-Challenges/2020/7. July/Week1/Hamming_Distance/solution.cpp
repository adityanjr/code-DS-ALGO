class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        
        while(x > 0 || y > 0) {
            result += (x % 2) ^ (y % 2);
            x /= 2;
            y /= 2;
        }
        
        return result;
    }
};