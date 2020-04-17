//  https://www.interviewbit.com/problems/ways-to-decode/

int decode(string A, int ind) {
    if(ind>=A.size())
        return 1;
    
    if(A[ind]=='0')
        return 0;
    
    int res = decode(A, ind+1);
    string st = A.substr(ind, 2);
    if(stoi(st)<27 and stoi(st)>9)
        res += decode(A, ind+2);
    
    return res;
}
int Solution::numDecodings(string A) {
    return decode(A, 0);
}

