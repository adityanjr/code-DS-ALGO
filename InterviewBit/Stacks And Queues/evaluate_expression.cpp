//  https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    stack<string> st;
    
    int n1, n2;
    
    int n = A.size();
    for(int i=0;i<n;i++) {
        if(A[i]!="+" && A[i]!="-" && A[i]!="/" && A[i]!="*") {
            //cout << A[i] << endl;
            st.push(A[i]);
        }
        else {
            stringstream sa(st.top());
            sa >> n2;
            st.pop();
            stringstream sb(st.top());
            sb >> n1;
            st.pop();
            //cout << n1 << " " << n2 << endl;
            if(A[i]=="+")
                st.push(to_string(n1+n2));
            else if(A[i]=="-") 
                st.push(to_string(n1-n2));
            else if(A[i]=="*")
                st.push(to_string(n1*n2));
            else if(A[i]=="/")
                st.push(to_string(n1/n2));
        }
       // cout << st.top() << endl;
    }
    int res; 
    stringstream ss(st.top());
    ss >> res;
    return res;
}


######### OR ###########

void print(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int Solution::evalRPN(vector<string> &A) {
    
    stack<int> st;
    
    auto i = 0;
    auto n = A.size();
    
    while(i<n) {
        int n1 = 0;
        int n2 = 0;
        if(A[i]!="/" && A[i]!="*" && A[i]!="+" && A[i]!="-") {
            stringstream ss(A[i]);
            auto x = 0;
            ss >> x;
            st.push(x);
            //cout << "it has been executed\n";
        }
        else {
            //print(st);
            n1 = st.top();
            st.pop();
            n2 = st.top();
            st.pop();
                
            switch(A[i][0]) {
                case '+': st.push(n1+n2);
                    break;
                case '-': st.push(n2-n1);
                    break;
                case '*': st.push(n2*n1);
                    break;
                case '/': st.push(n2/n1);
                    break;
                default:
                    return 0;
            }
        }
        
        i++;
    }
    if(st.empty())
        return 0;
    return st.top();
}

