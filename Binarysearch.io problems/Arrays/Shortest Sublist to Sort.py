"""
Given a list of integers nums, return the length of the shortest 
sublist in nums which if sorted would make nums sorted in ascending order.
"""

"""
Example-1
Input:

nums = [0, 1, 4, 3, 8, 9]
Output:
2
Explanation:
Sorting the sublist [4, 3] would get us [0, 1, 3, 4, 8, 9]

Example-2

Input:
nums = [5, 4, 3, 2, 8, 9]

Output:
4
Explanation:

Sorting the sublist [5, 4, 3, 2] would get us [2, 3, 4, 5, 8, 9]

Example-3
Input:

nums = [1, 2, 3, 5, 9, 8, 5]
Output:
3
Explanation:

Sorting the sublist [9, 8, 5] would get us [1, 2, 3, 5, 5, 8, 9]


"""
"""
Approach:
Using two pointer algorithm.Sort the array and let's call it as temp compare the low and high pointer elements in 
an array with the low and high pointer elements in the temp array if any element doesn't matches with original array there low and 
high pointers are fixed by using those positions we can calculate the length of the shortest subslist to sort

"""
def solve(nums):
    n=len(nums)
    low=0
    high=n-1
    temp=sorted(nums)
    while(n!=0):
        if(nums[low]==temp[low]):
            low+=1
        if(nums[high]==temp[high]):
            high-=1
        n-=1
    if(low>=high):
        return(0)
    return(high-low+1)     
if __name__=="__main__":
    nums=list(map(int,input().split()))
    print(solve(nums))
