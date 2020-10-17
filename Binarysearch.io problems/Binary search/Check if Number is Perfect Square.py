"""
Given an integer n, return whether n = k * k for some integer k.
This should be done without using built-in square root function.
"""
"""
Constraints:
0 ≤ n < 2 ** 31
"""
"""
Example-1:

Input:

n = 25

Output:

True

Explanation:

25 = 5 * 5


"""
"""
Approach:
Use binary search to continuously divide the number until the square of the number becomes equal to number itself.
"""
def solve(number):
    low=0
    high=number
    while(low<=high):
        mid=(low+high)//2
        if(mid*mid==number):
            return(True)
        elif(mid*mid<number):
            low=mid+1
        else:
            high=mid-1
    if(low>high):        
        return(False) 
if __name__=="__main__":
    number=int(input())
    print(solve(number))           
