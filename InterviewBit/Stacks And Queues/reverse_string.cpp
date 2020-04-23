//  https://www.interviewbit.com/problems/reverse-string/

string Solution::reverseString(string A) {
    
    stack<char> st;
    
    int l = A.length();
    
    for(int i=0;i!=l;i++)
        st.push(A[i]);
        
    A = "";    
    while(!st.empty()) {
        A += st.top();
        st.pop();
    }
    return A;
}
