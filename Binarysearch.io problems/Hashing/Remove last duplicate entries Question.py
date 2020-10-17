"""
Given a list of integers nums, find all duplicate numbers and delete their last occurrences.
For example, given [1, 3, 4, 1, 3, 5] return [1, 3, 4, 5].
"""
"""
Example-1:

Input: nums=[1,3,4,1,3,5]
output:[1,3,4,5]
"""
"""
Approach:  Use dictionary based hasing to keep a count of every digit occurred in an array.While iterating over an array if more than
once if a number is occured which means found in duplicates skip that element and move on to next element follow this process until iterating over the entire array

"""


from collections import Counter
def solve(nums):
    c=Counter(nums)  #keep a count on every element in an array
    new=[]
    duplicates={num for num,freq in c.items() if freq>1} # If any number occurs more than once consider it as a duplicate
    for num in nums:
        if(c[num]!=1 or num not in duplicates): # Check whether the number is in duplicates or not or frequency of the
                                                #  occurence of the number is not equal to 1
            new.append(num)
            c[num]-=1 # once iterating over the particular element is completed then decrease that element frequency by 1
    return(new)                                            
if __name__=="__main__":
    nums=list(map(int,input().split()))
    print(solve(nums))     