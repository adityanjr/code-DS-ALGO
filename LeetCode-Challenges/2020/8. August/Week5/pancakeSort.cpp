class Solution {
private:
    int find(vector<int>& A, int target) {
        for(int i = 0; i < A.size(); ++i)
            if(A[i] == target) return i;
        return -1;
    }
    
    void flip(vector<int>& A, int pos) {
        int i = 0;
        
        while(i < pos) {
            int temp = A[i];
            A[i++] = A[pos];
            A[pos--] = temp;
        }
    }
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> flips;
        
        for(int n = A.size(); n > 0; --n) {
            int index = find(A, n);
            
            flip(A, index);
            flip(A, n - 1);
            
            flips.push_back(index + 1);
            flips.push_back(n);
        }
        
        return flips;
    }
};