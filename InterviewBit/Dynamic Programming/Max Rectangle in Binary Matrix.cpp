//  https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int histArea(vector<int> A) {
    int n = A.size();
    stack<int> st;
    st.push(0);
    
    int top, area, max_area = 0, i=1;
    
    while(i<n) {
        while(A[st.top()] > A[i]) {
            top = st.top();
            st.pop();
            area = (st.empty())?(A[top]*i):(A[top]*(i-st.top()-1));
            max_area = max(area, max_area);
            if(st.empty())
                break;
        }
        st.push(i);
        ++i;
    }
    
    while(!st.empty()) {
        top = st.top();
        st.pop();
        area = (st.empty())?(A[top]*i):(A[top]*(i-st.top()-1));
        max_area = max(area, max_area);
    }
    return max_area;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    int ans = histArea(A[0]);
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++)
            A[i][j] = (A[i][j])?1+A[i-1][j]:A[i][j];
        ans = max(ans, histArea(A[i]));
    }
    return ans;
}

