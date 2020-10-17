"""
Given a non-negative integer n, find a number r such that r * r = n and round down to the nearest integer.
Can you implement this without using the built-in square root?
"""
"""
Example 1
Input

n = 9
Output

3
Explanation

3 is the square root of 9.

Example 2
Input

n = 26
Output

5
Explanation

~5.09901951359 is the square root of 26 and rounding down gives us 5.

"""

"""
Approach:
Use binary search to find the nearest Integer whose square is equal to n, and if there is no such integer, 
return the maximum integer whose square in less than the number "n"
"""

def solve(number):
    low=0
    high=number-1
    while(low<=high):
        mid=(low+high)//2
        if(mid*mid==number):
            return(mid)
        elif(mid*mid<number):
            low=mid+1
        else:
            high=mid-1
    if(low>high):
        return(high)
if __name__=="__main__":
    number=int(input())
    print(solve(number))                        