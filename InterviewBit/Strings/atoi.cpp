//  https://www.interviewbit.com/problems/atoi/

size_t highestOneBitPosition(uint32_t a) {
    size_t bits = 0;
    while(a!=0) {
        ++bits;
        a>>=1;
    }
    return bits;
}

bool multiplication_is_safe(uint32_t a, uint32_t b) {
    size_t a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
    return (a_bits+b_bits<=32);
}



int Solution::atoi(const string A) {
    
    int n = A.size();
    int num = 0, i=0;
    
    while(A[i]==' ')
        i++;
    int d = A[i]-'0';
    //check for garbage characters
    if((A[i]!='-' && A[i]!='+') && (d<0 || d>9))
        return 0;
    int flag = 0;
    if(A[i]=='-') {
        flag = 1;
        i++;
    }
    
    if(A[i]=='+')
        i++;
    
    for(;i<n;i++) {
        d = A[i]-'0';
        
        if(d>=0 && d<=9) {
            
            if(multiplication_is_safe(num, 10))
                num = num*10 + d;
            else if(num>0 && flag==0)
                return INT_MAX;
            else
                return INT_MIN;
        }
            
        else if(d<0 || d>0) {
            if(num!=0 && flag==1)
                return -num;
            return num;
        }
    }
    if(flag)
        return -num;
    return num;
}

