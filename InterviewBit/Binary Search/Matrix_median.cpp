//  https://www.interviewbit.com/problems/matrix-median/
//  Though the problem says extra memory not allowed, stil this gets accepted.

int Solution::findMedian(vector<vector<int> > &A) {
    vector<int> elem;
    
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[0].size();j++)
            elem.push_back(A[i][j]);
        
    sort(elem.begin(), elem.end());
    int index = elem.size()/2;
    //cout << index << endl;
    return elem[index];
}


