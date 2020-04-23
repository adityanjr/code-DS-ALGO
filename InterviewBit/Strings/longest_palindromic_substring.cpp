//  https://www.interviewbit.com/problems/longest-palindromic-substring/

string Solution::longestPalindrome(string A) {
    int maxLen = 1;
    int start = 0;
    int n = A.size();
    
    int low, high;
    
    for(int i=1;i<n;++i) {
        low = i-1;
        high = i;
        
        while(low>=0 && high<n && A[low]==A[high]) {
            if(high-low+1 > maxLen) {
                start = low;
                maxLen = high-low+1;
            }
            --low;
            ++high;
        }
        
        low = i-1;
        high = i+1;
        while(low>=0 && high<n && A[low]==A[high]) {
            if(high-low+1 > maxLen) {
                start = low;
                maxLen = high-low+1;
            }
            --low;
            ++high;
        }
    }
    return A.substr(start, maxLen);
}

