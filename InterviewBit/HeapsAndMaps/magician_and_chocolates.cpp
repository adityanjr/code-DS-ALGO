//  https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int A, vector<int> &B) {
    long long mod = pow(10, 9)+7;
    priority_queue<int> pq;
    
    for(auto b: B)
        pq.push(b);
    
    long long ans = 0;
    
    for(int i=0;i<A;i++) {
        int chocs = pq.top();
        pq.pop();
        ans = (ans + (long long)chocs)%mod;
        pq.push(chocs/2);
    }
    return ans;
}

