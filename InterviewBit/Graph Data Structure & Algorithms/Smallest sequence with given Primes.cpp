//  https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

vector<int> Solution::solve(int A, int B, int C, int D) {
    
    vector<int> numbers;
    
    if(D==0)
        return numbers;
    
    set<int> st;
    st.insert(A);
    st.insert(B);
    st.insert(C);
    
    while(!st.empty()) {
        int curr = *st.begin();
        st.erase(st.begin());
        numbers.push_back(curr);
        if(numbers.size()==D)
            break;
        int p1 = curr*A;
        int p2 = curr*B;
        int p3 = curr*C;
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    return numbers;
}

