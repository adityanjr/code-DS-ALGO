//  https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    int nflag = 0;
    if(A<0)
    {
        nflag++;
        A *= -1;
    }
    ostringstream ss;
    ss << A;
    string s = ss.str();
    for(int i=0;i<s.size()/2;i++)
    {
        s[i] ^= s[s.size()-1-i];
        s[s.size()-1-i] ^= s[i];
        s[i] ^= s[s.size()-1-i];
    }
    stringstream geek(s);
    int num = 0;
    geek >> num;
    return (nflag)?-num:num;
}

