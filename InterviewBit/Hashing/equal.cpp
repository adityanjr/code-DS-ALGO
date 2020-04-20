//  https://www.interviewbit.com/problems/equal/

vector<int> Solution::equal(vector<int> &A) {
    
    vector<int> result;
    vector<int> ans;
    
    int n = A.size();
    
    unordered_map<int, vector<int> > val;
    
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int sum = A[i] + A[j];
            
            if(val.find(sum)!=val.end()) {
                if(val[sum][0]<i && val[sum][1]!=i && val[sum][1]!=j) {
                    result.push_back(val[sum][0]);
                    result.push_back(val[sum][1]);
                    result.push_back(i);
                    result.push_back(j);
                    
                    if(ans.size()==0)
                        ans = result;
                    else if(ans > result) {
                        ans.clear();
                        ans = result;
                    }
                }
            }
            else {
                result.push_back(i);
                result.push_back(j);
                val[sum] = result;
            }
            result.clear();
        }
    }
    
    return ans;
}

