class Solution {
public:
    int minRemoveToMakeValid(string s) {
        const int n = (int)s.size();
        stack<int>st;
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                st.push(i);
                s[i]='.';
            }else if(s[i]==')'){
                if((!st.empty()) && s[st.top()]=='.'){
                    s[st.top()]='(';
                    st.pop();
                }else{
                    s[i]='.';
                }
            }
        }
        string res;
        for(int i=0;i<n;++i){
            if(s[i]!='.'){
                res+=s[i];
            }
        }
        // in leetcode we have to return the string but 
        // in Daily question problem we are asked to return the minimal
        // removals so if we subtract valid string size from total size then
        // we will be left with the total characters we have to remove. 
        // 
        // Note return type of function also needs to be changed.
        return n-(res.size());
    }
};

