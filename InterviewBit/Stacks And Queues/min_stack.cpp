//  https://www.interviewbit.com/problems/min-stack/

stack<int> st;
priority_queue<int, vector<int>, greater<int> > pq;

MinStack::MinStack() {
    while(!st.empty())
        st.pop();
    while(!pq.empty())
        pq.pop();
}

void MinStack::push(int x) {
    st.push(x);
    if(pq.empty())
        pq.push(x);
    else {
        if(x<=pq.top())
            pq.push(x);
        else 
            pq.push(pq.top());
    }
}

void MinStack::pop() {
    if(!st.empty()) {
        pq.pop();
        st.pop();
    }
}

int MinStack::top() {
    if(!st.empty())
        return st.top();
    return -1;
}

int MinStack::getMin() {
    if(!pq.empty())
        return pq.top();
    return -1;
}


