//  https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string B) {
    int n = B.size();
    
    string A;
    for(int i=0;i<n;i++) {
        if(B[i]!=' ')
            A = A + B[i];
    }
    
    n = A.size();
    
    stack<char> st;
    
    for(int i=0;i<n;i++) {
        if(A[i]=='(' || A[i]=='{' || A[i]=='[')
            st.push(A[i]);
        else if(A[i]==')' || A[i]=='}' || A[i]==']') {
            //cout << st.top() << " ";
            if((st.top()=='('&&A[i]==')') || (st.top()=='{'&&A[i]=='}') || (st.top()=='['&&A[i]==']'))
                st.pop();
            else
                return 1;
            
        }
        if(i>0 && i+1<n) {
            if(A[i-1]=='('&&A[i+1]==')')
                return 1;
        }
    }
    int f1=0,f2=0;
    for(int i=0;i<n;i++) {
        if((A[i]=='(' || A[i]=='{' || A[i]=='[') && (A[i+1]=='(' || A[i+1]=='{' || A[i+1]=='['))
            f1 = 1;
        if((A[i]==')' || A[i]=='}' || A[i]==']') && (A[i+1]==')' || A[i+1]=='}' || A[i+1]==']')) {
            f2 = 1;
            if(f1)
                break;
        }
            
        else if(A[i]==')' || A[i]=='}' || A[i]==']')
            f1 = 0;
    }
    if(f1 && f2)
        return 1;
    return 0;
}

