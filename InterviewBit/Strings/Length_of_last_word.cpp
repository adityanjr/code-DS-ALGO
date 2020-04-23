//  https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = 0;
    int end = A.length();
    
    int count = 0, wordEnd = end - 1;
    while(A[wordEnd]==' ')
        wordEnd--;
    if(wordEnd<0)
        return 0;
    while(A[wordEnd]!=' ')
    {
        count++;
        wordEnd--;
        if(wordEnd<0)
            break;
    }
    return count;
}

