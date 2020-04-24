//  https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    
    vector<string> data(B);
    if(B==1)
        return A;
    int a = 0, c, n=A.size();

    for(int i=0;i<n;i++) {

        data[a] += A[i];
        if(a==0)
            c = 1;
        if(a==B-1)
            c = -1;
        a = a+c;

    }
    string result;

    for(int i=0;i<B;i++) 
        result += data[i];
    
    return result;
}

