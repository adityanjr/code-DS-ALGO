//   https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;
    vector<int> ans;
    
    int i=0;
    for(;i<B;i++) {
        while(!dq.empty() && A[dq.back()]<A[i])
            dq.pop_back();
        dq.push_back(i);
    }
    
    ans.push_back(A[dq.front()]);
    
    while(i<A.size()) {
        if(i-dq.front()>=B)
            dq.pop_front();
            
        while(!dq.empty() && A[dq.back()]<A[i])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(A[dq.front()]);
        i++;
    }
    return ans;
}

