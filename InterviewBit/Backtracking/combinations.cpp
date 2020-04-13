//  https://www.interviewbit.com/problems/combinations/

vector<vector<int> > Solution::combine(int n, int B) {
    
    vector<vector<int> > result;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        A[i] = i+1;
        
    int lim = pow(2, n);
    vector<int> temp;
    for(int i=0;i<lim;i++) {
        
        for(int j=0;j<n;j++) {
            if(i&(1<<j))
                temp.push_back(A[j]);
        }
        if(temp.size()==B) {
            sort(temp.begin(), temp.end());
            result.push_back(temp);
        }
        temp.clear();
    }
    sort(result.begin(), result.end());
    return result;
}

######## ANOTHER SOLUTION ###########

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > result;
    
    auto lim = pow(2, A);
    
    for(auto i=0;i<lim;i++) {
        vector<int> temp;
        for(auto j=0;j<A;j++) {
            if(i&(1<<j))
                continue;
            temp.push_back(j+1);
        }
        if(temp.size()==B) {
            sort(temp.begin(), temp.end());
            result.push_back(temp);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

######## ANOTHER ONE ############3

void generateSet(vector<int> N, int index, vector<int> &current, vector<vector<int> > &result, int k) {
    if(index>=N.size()) {
        if(current.size()==k)
            result.push_back(current);
        return;
    }    
    generateSet(N, index+1, current, result, k);
    current.push_back(N[index]);
    generateSet(N, index+1, current, result, k);
    current.pop_back();
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > result;
    vector<int> current;
    
    vector<int> N;
    for(auto i=1;i<=A;i++)
        N.push_back(i);
    
    generateSet(N, 0, current, result, B);
    sort(result.begin(), result.end());
    return result;
}

