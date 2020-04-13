//   https://www.interviewbit.com/problems/combination-sum/

void getSum(int sum, int index, vector<int> A, vector<int> &current, set<vector<int> > &result) {
    if(sum==0) {
        result.insert(current);
        return;
    }
    if(index>=A.size() || sum<0)
        return;
    // include the number
    getSum(sum, index+1, A, current, result);
    // exclude the number
    current.push_back(A[index]);
    getSum(sum-A[index], index, A, current, result);
    current.pop_back();
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector<vector<int> > result;
    set<vector<int> > sets;
    vector<int> current;
    
    sort(A.begin(), A.end());
    getSum(B, 0, A, current, sets);
    for(auto st: sets)
        result.push_back(st);
    sort(result.begin(), result.end());
    return result;
}

