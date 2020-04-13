//  https://www.interviewbit.com/problems/permutations/

int nextNum(vector<int> &A) {
    int n = A.size();
    int i = n-1;
    for(;i>0;i--) {
        if(A[i]>A[i-1])
            break;
    }
    if(i==0)
        return 0;
    int index = i-1;

    int smallest = i;
    for(int j=i+1;j<n;j++) {
        if(A[index]<A[j] && A[j]<A[smallest])
            smallest = j;
    }
    int temp = A[smallest];
    A[smallest] = A[index];
    A[index] = temp;
  
    sort(A.begin()+index+1, A.end());
    return 1;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    sort(A.begin(), A.end());
    vector<vector<int> > result;
    result.push_back(A);
    if(A.size()<2)
        return result;
    while(1) {
        
        if(nextNum(A)) {
            result.push_back(A);
        }
        else
            break;
    }
    return result;
}

