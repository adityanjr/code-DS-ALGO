//  https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B) {
    
    int n = A.size();
    int m = B.size();

    if(n==0)
        return B;
    if(m==0)
        return A;

    if(m>n) {
        string temp = A;
        A = B;
        B = temp;
        n = A.size();
        m = B.size();
    }

    int i=1, sum, carry = 0;
    string result = "";

    while(i<=n && i<=m ) {

        int p = A[n-i]-'0';
        int q = B[m-i]-'0';

        if(p==1 && q==1) {
            if(carry==1) {
                sum = 1;
                carry = 1;
            }
            else {
                sum = 0;
                carry = 1;
            }
        }
        else if((p==1 && q==0) || (p==0 && q==1)) {
            if(carry==1) {
                sum = 0;
                carry = 1;
            }
            else {
                sum = 1;
                carry = 0;
            }
        }
        else if(p==0 && q==0) {
            if(carry==1) {
                sum = 1;
                carry = 0;
            }
            else {
                sum = 0;
                carry = 0;
            }
        }
       result = to_string(sum) + result;
       i++;
    }

    if(n==m) {
        if(carry==1)
            result = to_string(carry) + result;
        return result;
    }
    else {
        while(i<=n) {

            int p = A[n-i]-'0';
            if(p==1) {
                if(carry==1) {
                    sum = 0;
                    carry = 1;
                }
                else {
                    sum = 1;
                    carry = 0;
                }
            }
            else {
                if(carry==1) {
                    sum = 1;
                    carry = 0;
                }
                else {
                    sum = 0;
                    carry = 0;
                }
            }
            result = to_string(sum) + result;
            i++;
        }
    }

    if(carry==1)
        result = to_string(carry) + result;

    return result;
}

