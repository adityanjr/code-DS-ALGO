//  https://www.interviewbit.com/problems/colorful-number/

int Solution::colorful(int A) {
    unordered_map<long long int, int> mp;
    string st = to_string(A);
    
    for(int i=0;i<st.length();i++) {
        int prod = 1;
        for(int j=i;j<st.length();j++) {
            prod *= st[j]-'0';
            if(mp.find(prod)!=mp.end())
                return 0;
            else
		mp[prod] = 1;
                //mp.insert(make_pair(prod, 1));
        }
    }
    return 1;
}

