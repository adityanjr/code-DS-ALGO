//  https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int sz = 0, row = 0, col = 0;
    int n = A.size();
    vector<vector<int> > result;
    for(int l=0;l<2*n-1;l++) {
        if(l<n)
            sz++;
        else
            sz--;
        vector<int> elem;
        int k = 0;
        int i = row;
        int j = col;
        
        while(k<sz) {
            elem.push_back(A[i][j]);
            i++;
            j--;
            k++;
        }
        if(col<n-1)
            col += 1;
        else
            row += 1;
        result.push_back(elem);
    } 
    return result; 
}

