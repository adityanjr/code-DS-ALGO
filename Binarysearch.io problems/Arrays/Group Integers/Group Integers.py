"""
Approach:
According to the conditions we need to divide an array such that every sub group need to have atleast 2 elements and all the integers
in a particular sub group should be the same and sizes of all groups should be the same.By clear observation suppose if make a sub 
group with "x" elements then the next sub group to be formed must be divisible by "x" otherwise size of all sub groups rule is violated.
So inorder to pick what is the size of each subgroup to be formed we calculate a "gcd" of the occurence of each element if that "gcd>1"
then subgroups with given rules are formed.Here use hashing for keeping count of each unique element  

"""
from collections import Counter
from math import gcd
def group_integers(nums):
    uniqueCount=Counter(nums) #Finding the count of each unique element
    uniqueCount=list(uniqueCount.values())
    common_gcd=uniqueCount[0]
    for i in range(1,len(uniqueCount)):
        common_gcd=gcd(uniqueCount[i],common_gcd)
    if(common_gcd>1):
        return(True)
    elif(common_gcd==1):
        return(False)
if __name__=="__main__":
    """
    nums=list(map(int,input().split()))
    print(group_integers(nums))   
    """
    nums = [2, 3, 5, 8, 3, 2, 5, 8]
    print(group_integers(nums))             


