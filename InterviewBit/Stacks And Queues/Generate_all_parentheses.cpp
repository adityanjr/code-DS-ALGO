void print(stack<char> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int Solution::isValid(string A) {

    stack<char> st;
    
    auto n = A.size();
    auto i = 0;
    if(A[i]==')' || A[i]=='}' || A[i]==']')
        return 0;
    while(i<n) {
        if(A[i]=='{' || A[i]=='(' || A[i]=='[')
            st.push(A[i]);
        else {
            if(st.empty())
                return 0;
            char op = st.top();
            st.pop();
            if((A[i]==')' && op=='(') || (A[i]=='}' && op=='{') || (A[i]==']' && op=='['))
                ;
            else
                return 0;
        }
        //print(st);
        i++;
    }
    if(st.empty())
        return 1;
    return 0;
}

