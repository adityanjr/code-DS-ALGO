//  https://www.interviewbit.com/problems/valid-number/

int Solution::isNumber(const string str) {
    string A = "";
    int flg_s = 1;
    for(int i =0;i<str.size();i++)
    {
        if(str[i]!=' ')
            flg_s = 0;
        if(flg_s==0)
            A += str[i];
    }
    //cout << A << endl;
    int n = A.size()-1;
    
    while(n>=0 && A[n]==' ')
        --n;
    A = A.substr(0, n+1);
    n = A.size();
    
    int i = 1, flg_e = 0, flg_d = 0;
    if(A[0]<'0' || A[0]>'9')
    {
        if(A[0]!='.' && A[0]!='-')
            return 0;
    }
    if(A[n-1]<'0' || A[n-1]>'9')
        return 0;
        
    while(i<n)
    {
        if((A[i]<'0' || A[i]>'9') && A[i]!='e' && A[i]!='.' && A[i]!='-')
            return 0;
        else if(A[i]=='e')
        {
            flg_e++;
            if(flg_e>1)
                return 0;
        }
        else if(A[i]=='-')
        {
            if(A[i-1]!='e')
                return 0;
        }
        else if(A[i]=='.')
        {
            flg_d++;
            if(flg_d>1 || flg_e)
                return 0;
            if(i+1<n && (A[i+1]<'0'||A[i+1]>'9'))
                return 0;
        }
        i++;
    }
    return 1;
}

