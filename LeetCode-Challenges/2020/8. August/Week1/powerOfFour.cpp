class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0) return false;
        
        while(num != 1) {
            if(num % 4 != 0) return false;
            num /= 4;
        }
        
        return true;
    }
};

/*
    Without Loop - Using Log property
    Read more - https://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
*/
class Solution {
    float logn(int n, int r) {
        return log(n) / log(r);
    }
public:
    bool isPowerOfFour(int num) {
        if(num == 0) return false;
        return floor(logn(num, 4)) == ceil(logn(num, 4));
    }
};