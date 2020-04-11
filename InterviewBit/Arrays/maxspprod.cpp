//  https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) {
    int mod = 1000000007;
    int n = A.size();
    vector<long long> lsp(n);
    vector<long long> rsp(n);
    stack<int> st;
    
    for(int i=0;i<n;i++) {
        while(!st.empty()) {
            if(A[st.top()] <= A[i])
                st.pop();
            else
                break;
        }
        if(st.empty())
            lsp[i] = 0;
        else
            lsp[i] = st.top();
        st.push(i);
    }
    stack<int>().swap(st);
    
    for(int i=n-1;i>=0;i--) {
        while(!st.empty()) {
            if(A[st.top()] <= A[i])
                st.pop();
            else
                break;
        }
        if(st.empty())
            rsp[i] = 0;
        else
            rsp[i] = st.top();
        st.push(i);
    }
    
    long long ans = lsp[0]*rsp[0];
    for(int i=1;i<n;i++) {
        ans = max(ans, lsp[i]*rsp[i]);
        ans = ans%mod;
    }
    return (int)ans;
}

