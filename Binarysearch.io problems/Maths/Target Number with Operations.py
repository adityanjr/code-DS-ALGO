"""
Given positive integers start and end (start < end), return the minimum number of operations needed to 
convert start to end using these operations:
  1.Increment by 1
  2.Multiply  by 2
"""
"""
Example-1:

Input:
start=2
end=9

Output:
3
"""

"""
Approach:
Start from end by dividing with 2 if it is even and if it is odd decrement it by 1 and return the count
"""
def solve(start,end):
    count=0
    while(end//2>=start):
        if(end%2==1):
            end-=1
            end//=2
            count+=2
        else:
            end//=2
            count+=1
    count+=end-start
    return(count) 
if __name__=="__main__":
    start=int(input())
    end=int(input())
    print(solve(start,end))               
