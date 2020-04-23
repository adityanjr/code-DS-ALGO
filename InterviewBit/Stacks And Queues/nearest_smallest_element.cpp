// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> res;
    res.push_back(-1);
    stack<int> S;
    
    S.push(A[0]);
    
    for(int i=1;i<A.size();i++)
    {
    
        while(A[i]<=S.top())
        {
            S.pop();
        }
    
        if(S.empty())
        res.push_back(-1);
        else
        res.push_back(S.top());
        
        S.push(A[i]);
       
    }
    return res;
}
