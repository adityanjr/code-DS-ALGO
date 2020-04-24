//  https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

vector<int> prefixTable(string A) {
    
    int n = A.size();
    vector<int> F(n);
    F[0] = 0;
    int i = 1, j=0;
    
    while(i<n) {
        
        if(A[i]==A[j]) {
            F[i] = j+1;
            i++;
            j++;
        }
        else if(j) {
            j = F[j-1];
        }
        else
            i++;
    }
    return F;
    
}

string reverseString(string A) {
    
    string s = "";
    int n = A.size();
    
    for(int i=n-1;i>=0;i--)
        s += A[i];
    
    return A + "$" + s;
    
}

int Solution::solve(string A) {
    
    string st = reverseString(A);
    int n = A.size();
    int m = st.size();
    vector<int> F = prefixTable(st);
    
    return n-F[m-1];
    
}

