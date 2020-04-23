//  https://www.interviewbit.com/problems/implement-strstr/

void preComp(string A, vector<int> &F){
    int m = A.size();
    int j=0,i=1;
    F[0] = 0;
    while(i<m)
    {
        if(A[i]==A[j])
        {
            F[i] = j+1;
            i++;
            j++;
        }
        else if(j)
            j = F[j-1];
        else
        {
            F[i] = j;
            i++;
        }
    }
}

int Solution::strStr(const string haystack, const string needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int txt_len = haystack.size();
    int pat_len = needle.size();
    int flag = 0;
    
    if(txt_len < pat_len){
        return -1;
    }
    
    if(pat_len == 0){
        return 0;
    }
    
    vector<int> pre(pat_len);
    
    preComp(needle, pre);
    
    int i=0; // for haystack
    int j=0; // for needle
    
    while(i<txt_len && j<pat_len)
    {
        if(haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else if(j)
            j = pre[j-1];
        else
            i++;
    }
    
    return (j==pat_len)?i-j:-1;
    
}


