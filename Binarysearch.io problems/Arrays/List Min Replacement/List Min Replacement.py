"""
Approach:
If we observe the question clearly it is about replacing the current index element with the minimum element
so far just before the current index element 

"""
def solve(nums):
  if(nums):
    minsofar=nums[0]
    nums[0]=0
    for i in range(1,len(nums)):
        currentElement=nums[i]
        nums[i]=minsofar
        minsofar=min(minsofar,currentElement)
    return(nums)    

  else:
      return(nums)  
if __name__=="__main__":
    """
    nums=list(map(int,input().split()))
    print(solve(nums))  
    """
    nums=[10, 5, 7, 9] 
    print(solve(nums))   