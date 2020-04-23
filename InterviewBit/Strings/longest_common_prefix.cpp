//  https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    string pref = "";
    int n = A.size();
    
    if(n==1)
        return A[0];
    
    int j = 0, flg = 1;
    while(flg)
    {
        char c = A[0][j];
        for(int i=1;i<n;i++)
        {
            if(j<A[i].size())
            {
                if(A[i][j]!=c)
                {
                    flg = 0;
                    break;
                }   
            }
            else
            {
                flg = 0;
                break;
            }
        }
        j++;        
        if(flg)
            pref = pref + c;
    }
    return pref;
}

