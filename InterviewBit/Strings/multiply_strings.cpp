//  https://www.interviewbit.com/problems/multiply-strings/

string add(string s1, string s2) {
    string result;
    result += s1[0];
    int i=1, j=0, carry = 0;
    while(i<s1.size() && j<s2.size()) {
        int n1 = s1[i]-'0';
        int n2 = s2[j]-'0';
        int sum = n1 + n2 + carry;
        int rem = sum%10;
        carry = sum/10;
        result += rem+'0';
        i++;
        j++;
    }
    
    while(j<s2.size()) {
        int n = s2[j]-'0';
        int sum = n + carry;
        int rem = sum%10;
        carry = sum/10;
        result += rem+'0';
        j++;
    }
    while(i<s1.size()) {
        int n = (s1[i]-'0') + carry;
        int rem = n%10;
        carry = n/10;
        result += rem+'0';
        i++;
    }
    if(carry>0) {
        string addn = to_string(carry);
        reverse(addn.begin(), addn.end());
        result += addn;
    }
    return result;
}

string Solution::multiply(string A, string B) {
    int i = 0;
    string temp;
    while(i<A.size()) {
        if(A[i]>='0' && A[i]<='9')
            temp += A[i];
        i++;
    }

    A = temp;
    temp.clear();
    
    i = 0;
    while(i<B.size()) {
        if(B[i]>='0' && B[i]<='9')
            temp += B[i];
        i++;
    }
    B = temp;
    int n = A.size();
    int m = B.size();
    
    int zf1 = 1, zf2 = 1;
    for(int i=0;i<n;i++)
        if(A[i]!='0') {
            zf1 = 0;
            break;
        }
    for(int i=0;i<m;i++)
        if(B[i]!='0') {
            zf2 = 0;
            break;
        }
    if(zf1 || zf2)
        return "0";
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    stack<string> products;
    
    for(i=0;i<n;i++) {
        
        int carry = 0;
        int n1 = A[i]-'0';
        string row = "";
        
        for(int j=0;j<m;j++) {
            
            int n2 = B[j]-'0';
            int prod = n1*n2 + carry;
            int rem = prod%10;
            carry = prod/10;
            row += rem+'0';
            
        }
        while(carry>0) {
            int rem = carry%10;
            carry /= 10;
            row += rem+'0';
        }
        
        products.push(row);
    }
    
    //cout << products.size() << endl;
    while(products.size()!=1) {
        string s1 = products.top();
        products.pop();
        string s2 = products.top();
        products.pop();
        products.push(add(s2, s1));
    }
    
    string result = products.top();
    products.pop();
    stack<string>().swap(products);
    reverse(result.begin(), result.end());
    
    while(result[0]=='0')
        result.erase(result.begin());
    
    //cout << result << endl;
    return result;
}

