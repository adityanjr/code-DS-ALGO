class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size();
        
        for(int i = n - 1; i >= 0; --i) {
            if(digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};