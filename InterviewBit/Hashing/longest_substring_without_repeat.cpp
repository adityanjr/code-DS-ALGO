// https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {
    
    int n = A.size();
    if(n<2)
        return n;
    int len = INT_MIN;
    unordered_map<char, int> chars; 
    int i = 0;
    while(i<n-1) {
        chars[A[i]] = i;
        for(int j=i+1;j<n;j++) {
            if(chars.find(A[j])==chars.end()) {
                chars[A[j]] = j;
            }
            else {
                len = max(len, j-i);
                i = chars[A[j]]+1;
                chars.clear();
                break;
            }
            if(j==n-1)
                len = max(len, j-i+1);
        }
        //cout << len << endl;
    }
    return len;
}

