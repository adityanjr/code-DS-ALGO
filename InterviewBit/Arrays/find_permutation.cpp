//  https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    
    int l=1, r=B;
    
    vector<int> result;
    
    for(int i=0;i<B-1;i++) {
        if(A[i]=='I') {
            result.push_back(l);
            l++;
        }
        else if(A[i]=='D') {
            result.push_back(r);
            r--;
        }
    }
    result.push_back(l);
    return result;
}

