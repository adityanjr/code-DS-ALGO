//  https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    char *str = new char[A.size()+1];
    memcpy(str, A.c_str(), A.size()+1);
    int count = 0;
    for(int i=0;str[i];i++)
    {
        if(isalnum(str[i]))
        {
            str[count] = str[i];
            count++;
        }
    }
    str[count] = '\0';
    
    int start = 0;
    int end = strlen(str)-1;
    while(start < end)
    {
        if(tolower(str[start])!=tolower(str[end]))
            return 0;
        start++;
        end--;
    }
    return 1;
}

