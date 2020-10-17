"""
Given a list of integers nums, return the largest integer k where k and -k 
both exist in nums (they can be the same integer). If there's no such integer, return -1.
"""
"""
Example-1:
Input:
nums = [-4, 1, 8, -5, 4, -8]

output:
8

Example-2
Input:
nums = [5, 6, 1, -2]
Output:
-1

"""
"""
Approach:
Use dictionaries to keep every element in a dictionary.Finding a negative number such that positive version of that number is already 
present and that number should be the maximum is the criteria
Note:Additive inverse of 0 is 0
"""

def solve(nums):
    hash={}
    mx=-1
    for num in nums:
        if(-num in hash or num==0):
            mx=max(abs(num),mx)
        else:
            hash[num]=1
    return(mx) 
if __name__=="__main__":
    nums=list(map(int,input().split()))
    print(solve(nums))               