//  https://www.interviewbit.com/problems/fraction/

string Solution::fractionToDecimal(int n1, int n2) {
    string result;
    int64_t A = n1;
    int64_t B = n2;
    
    int an = 0, bn = 0;
    if(A==0)
        return "0";
        
    if(A<0) {
        an = 1;
        A *= -1;
    }
    if(B<0) {
        bn = 1;
        B *= -1;
    }
    
    int df = 0;
    unordered_map<int, int> mp;
    int64_t rem;
    while(1) {
        if(A==0)
            break;
        if(A<B) {
            if(df==0) {
                if(result.size()==0)
                    result = "0.";
                else
                    result += '.';
            }
            df++;
            A *= 10; 
        }
        
        if(df>0) {
            if(mp.find(A)==mp.end()) {
                mp.insert(pair<int, int> (A, df));
            }
            else {
                result += ')';
                int i=0;
                while(result[i]!='.') {
                    i++;
                    if(i==result.size())
                        break;
                }
                if(i<result.size())
                    result.insert(i+mp[A], "(");
                break;
            }
        }
            
        rem = A/B;
        A = A%B;
        result += to_string(rem);
    }
    
    if((an==1 && bn==0) || (an==0 && bn==1))
        result.insert(0, "-");
    return result;
}

