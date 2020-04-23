//  https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    stack<string> st;
    
    int n = A.size();
    for(int i=1;i<n;i++) {
        if(A[i]=='.'&&A[i+1]=='.') {
            if(!st.empty())
                st.pop();
        }
        else if(A[i]=='.')
            continue;
        else {
            string a;
            while(A[i]!='/') {
                a += A[i];
                i++;
                if(i==n)
                    break;
            }
            if(a.size()!=0)
                st.push(a);
        }
    }
    string path;
    if(!st.empty()) {
        path = st.top();
        st.pop();
    }
        
    while(!st.empty()) {
        path = st.top() + "/" + path;
        st.pop();
    }
    return "/"+path;
}

####### OR ################3

string Solution::simplifyPath(string A) {
    stack<string> st;
    
    auto i=0;
    while(i<A.size()) {
        if(A[i]=='.' && A[i+1]=='.') {
            if(!st.empty())
                st.pop();
        }
        else if(A[i]=='.')
            ;
        else if(A[i]!='/') {
            string pt = "";
            while(A[i]!='/' && i<A.size()) {
                pt += A[i];
                i++;
            }
            st.push(pt);
        }
        i++;
    }
    
    string path = "";
    
    while(!st.empty()) {
        path = "/" + st.top() + path;
        st.pop();
    }
    if(path.size()==0)
        return "/";
    return path;
}


