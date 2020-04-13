// https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalin(string A, int start, int final) {
    int i=start, j=final;
    
    while(i<j) {
        if(A[i]!=A[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void createPart(string A, int index, vector<vector<string> > &result, vector<string> &current) {
    int n = A.size();
    if(index>=n) {
        result.push_back(current);
        return;
    }
    
    for(int i=index;i<n;i++) {
        if(isPalin(A, index, i)) {
            current.push_back(A.substr(index, i-index+1));
            createPart(A, i+1, result, current);
            current.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string> > result;
    vector<string> current;

    createPart(A, 0, result, current);
    
    return result; 
    
}

