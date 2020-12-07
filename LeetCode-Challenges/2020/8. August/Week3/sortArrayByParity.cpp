/*
    With Extra Space - Intuitive Approach
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        
        for(int n: A) {
            if(n % 2 == 0) even.push_back(n);
            else odd.push_back(n);
        }
        
        for(int n: odd) {
            even.push_back(n);
        }
        
        return even;
    }
};

/*
    In-Place Sort, Without Extra space
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        if(n == 0 || n == 1) return A;
        
        int idx = 0;
        
        for(int i = 0; i < n; ++i) {
            if(A[i] % 2 == 0) swap(A[idx++], A[i]);
        }
        
        return A;
    }
};