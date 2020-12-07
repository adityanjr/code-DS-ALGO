class Solution {
public:
    int addDigits(int num) {
        int digitNum = 0;
        while(num > 0) {
            digitNum += num % 10;
            num /= 10;
            
            if(digitNum > 9 && num == 0) {
                num = digitNum;
                digitNum = 0;
            }
        }
        
        return digitNum;
    }
};

/*
    Follow Up in O(1)
    @see: https://leetcode.com/problems/add-digits/solution/
*/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};