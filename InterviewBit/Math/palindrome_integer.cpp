//  https://www.interviewbit.com/problems/palindrome-integer/

/**
 * @input A : Integer
 * 
 * @Output Integer 0 / 1. Return 0 if the number is not palindrome, else return 1
 */
int isPalindrome(int A) {
    if(A<0)
        return 0;
    int rem;
    int i=A;
    int num=0;
    while(i>0)
    {
        rem = i%10;
        num = rem + num*10;
        i = i/10;
    }
    if(num==A)
        return 1;
    else
        return 0;
}

