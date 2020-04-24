//  https://www.interviewbit.com/problems/power-of-2/

string divideBy2(string A) {
    
    int n = A.size(), i=0, p=0;
    string result = "";
    while(i<n) {

        p = p*10 + A[i]-'0';
        while(p<2) {
            i++;
            p = p*10 + A[i]-'0';
            if(result.size()!=0)
                result += "0";
        }
        result += to_string(p/2);
        p = p%2;
        i++;
    }
    
    return result;
}

int Solution::power(string A) {
    
    string curr_str = A;
    int num, n;
    
    if(A=="0" || A=="1")
        return 0;
    
    while(1) {
        
        n = curr_str.size();
        if((curr_str[n-1]-'0')%2!=0)
            return 0;
        curr_str = divideBy2(curr_str);
        //cout << curr_str << endl;
        if(curr_str=="1")
            return 1;

    }
    
    return 0;
}

