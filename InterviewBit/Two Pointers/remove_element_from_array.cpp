//  https://www.interviewbit.com/problems/remove-element-from-array/

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    
    A.erase(remove(A.begin(), A.end(), B), A.end());
    return A.size();
}

