//  https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int> > res;
    if(A.size()<3) {
        return res;
    }
    set<vector<int>> triplets;
    sort(A.begin(), A.end());
    for(int i=0;i<A.size()-2;i++) {
        int j=i+1, k=A.size()-1;
        vector<int> elem;
        while(j<k) {
            int sum = A[i]+A[j]+A[k];
            if(sum==0) {
                
                elem.push_back(A[i]);
                elem.push_back(A[j]);
                elem.push_back(A[k]);
                
                triplets.insert(elem);
                
                elem.clear();
                j++;
        
            }
            else if(sum>0)
                k--;
            else
                j++;
        }
    }
    
    set<vector<int> >::iterator it;
    for(it=triplets.begin();it!=triplets.end();it++) 
        res.push_back(*it);
    
    return res;
}

