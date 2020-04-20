//  https://www.interviewbit.com/problems/2-sum/

int findInd(vector<int> A, int B) {
    for(int i=0;i<A.size();i++)
        if(A[i]==B)
            return i;
    return 0;
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {

    vector<int> index;
    unordered_set<int> hash;
    
    for(int i=0;i<A.size();i++) {
        if(hash.find(B-A[i])==hash.end())
            hash.insert(A[i]);
        else {
            index.push_back(1+findInd(A, B-A[i]));
            index.push_back(i+1);
            break;
        }
    }
    return index;
}

