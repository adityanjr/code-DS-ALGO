//  https://www.interviewbit.com/problems/pretty-json/

vector<string> Solution::prettyJSON(string A) {
    
    vector<string> result;
    
    int n = A.size();
    int i = 0;

    string t(1, A[i]);
    result.push_back(t);
    i++;
    while(A[i]==' ')
        i++;
        
    string tabs;
    
    while(i<n) {
        string st;
        if(A[i-1]=='[' || A[i-1]=='{')
            tabs += "\t";
        
        while(A[i]!=',' && A[i]!='[' && A[i]!='{' && A[i]!='}' && A[i]!=']') {
            st += A[i];
            i++;
        }
        
        if(A[i]==',') {
            st += ',';
            i++;
            while(A[i]==' ')
                i++;
        }
        if(st.size())
            result.push_back(tabs+st);
        
        if(A[i]=='[' || A[i]=='{') {
            string s(1, A[i]);
            result.push_back(tabs+s);
            i++;
            while(A[i]==' ')
                i++;
        }
        
        else if(A[i]==']' || A[i]=='}') {
            
            tabs.pop_back();
            string s(1, A[i]);
            i++;
            if(A[i]==',') {
                s += A[i];
                i++;
            }
            result.push_back(tabs+s);
            while(A[i]==' ')
                i++;
        }
    }
    
    return result;
}

