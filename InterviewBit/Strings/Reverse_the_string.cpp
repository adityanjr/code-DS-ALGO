//  https://www.interviewbit.com/problems/reverse-the-string/

void reverseString(string &str, int start, int end)
{
    char temp;
    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = 0;
    int end = A.length();
    reverseString(A, start, end-1);
    int wordStart, wordEnd;
    wordStart = wordEnd = 0;
    while(wordEnd < end)
    {
        if(A[wordEnd]!=' ')
        {
            wordStart = wordEnd;
            while(A[wordEnd]!=' ' && wordEnd<end)
                wordEnd++;
            wordEnd--;
            reverseString(A, wordStart, wordEnd);
        }
        wordEnd++;
    }
}

