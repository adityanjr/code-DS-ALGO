//  https://www.interviewbit.com/problems/subset/

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > res;
    int n = A.size();
    int LIM = pow(2, n);
    
    for(int i=0;i<LIM;i++) {
        vector<int> temp;
        for(int j=0;j<n;j++) {
            if(i&(1<<j))
                continue;
            temp.push_back(A[j]);
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    sort(res.begin(), res.end());
    return res;
}


########## OR ##############

void generateSets(vector<int> &A, int index, vector<int> &set, vector<vector<int> > &sets) {
    if(index >= A.size()) {
        sets.push_back(set);
        return;
    }
    //ignore the current index
    generateSets(A, index+1, set, sets);
    //include the current index
    set.push_back(A[index]);
    generateSets(A, index+1, set, sets);
    set.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {

    vector<int> set;
    vector<vector<int> > sets;
    sort(A.begin(), A.end());
    generateSets(A, 0, set, sets);
    sort(sets.begin(), sets.end());
    return sets;
}


