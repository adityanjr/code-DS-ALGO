//  https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> R;
    int i=0, j=0;
    int n = A.size(), m = B.size();
    
    if(n==0) {
        A = B;
        return;
    }
        
    if(m==0)
        return;
    
    while(i<n && j<m) {
        if(A[i]<B[j]) {
            R.push_back(A[i]);
            i++;
        }
        else {
            R.push_back(B[j]);
            j++;
        }
    }
    
    while(i<n){
        R.push_back(A[i]);
        i++;
    }
    
    while(j<m){
        R.push_back(B[j]);
        j++;
    }
    A = R;
}


############ OR ############

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    auto n = A.size();
    auto m = B.size();
    
    auto i=0, j=0;
    while(A[i]>B[j] && j<m) {
        A.insert(A.begin()+i, B[j]);
        j++;
        i++;
    }
    
    while(j<m) {
        if(A[i]<=B[j])
            i++;
        else {
            A.insert(A.begin()+i, B[j]);
            i++;
            j++;
        }
        if(i>=A.size())
            break;
    }
    while(i>=n && j<m) {
        A.push_back(B[j]);
        j++;
    }
}



