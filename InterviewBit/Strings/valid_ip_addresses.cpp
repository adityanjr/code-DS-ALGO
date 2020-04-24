//  https://www.interviewbit.com/problems/valid-ip-addresses/

bool isValid(string A) {
    vector<string> ips;
    string s;
    int i=0;
    while(i<A.size()) {
        while(i<A.size() && A[i]!='.') {
            s += A[i];
            i++;
        }
        ips.push_back(s);
        s = "";
        i++;
    }
    
    for(auto ip: ips) {
        if(ip.size()>3 || stoi(ip)<0 || stoi(ip)>255)
            return false;
        if(ip.size()>1 && (stoi(ip)==0 || ip[0]=='0'))
            return false;
    }
    return true;
}
vector<string> Solution::restoreIpAddresses(string A) {
    
    vector<string> ans;
    if(A.size()>12 || A.size()<1)
        return ans;
    int n = A.size();
    string ip = A;
    for(int i=1;i<n-2;i++) {
        for(int j=i+1;j<n-1;j++) {
            for(int k=j+1;k<n;k++) {
                ip = ip.insert(k, ".");
                ip = ip.insert(j, ".");
                ip = ip.insert(i, ".");
                
                if(isValid(ip))
                    ans.push_back(ip);
                ip = A;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

