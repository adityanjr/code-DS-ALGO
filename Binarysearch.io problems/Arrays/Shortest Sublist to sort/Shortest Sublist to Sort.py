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
