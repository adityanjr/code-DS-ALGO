"""
Approach-1:
If we observe the given 2d array.Array is increasing from left to right as well as increasing from top to bottom.so
approach is to start from top right and
(1)If the current element is greater than target which means all the elements in the current column is greater than 
the target.So exclude that column and go to previous column i.e move left
(2)If the current element is less than target which mean all the elements in the current row is less than 
the target.so exclude that column and go to next row
"""

def solve(matrix,target):
    column=len(matrix[0])-1
    for row in matrix:
        while(column>=0 and row[column]>target):
            column-=1
        while(column>=0 and row[column]==target):
            return(True)
    return(False)    
if __name__=="__main__":
    """
    m,n=map(int,input().split())
    matrix=[[int(input()) for c in range(n)]for r in range(m)]
    target=int(input())
    print(solve(matrix,target))  
    """
    matrix = [
    [1, 3, 9],
    [2, 5, 10],
    [5, 7, 13]
]
target = 7 
print(solve(matrix,target))     


"""
Approach-2:
Traverse across each row and use the Binary search algorithm to find the target required
"""    
def solve(matrix,target):
    for r in range(len(matrix)):
        if(search(matrix[r][:],target)):
            return(True)
    return(False)
def search(matrix,target):
    low=0
    high=len(matrix[0])-1
    while(low<=high):
        mid=(low+high)//2
        if(target==matrix[i][mid]):
            return(True)
        elif(target<matrix[i][mid]):
            high=mid-1
        else:
            low=mid+1
    return(False)                            
if __name__=="__main__":
    """
    m,n=map(int,input().split())
    matrix=[[int(input()) for c in range(n)]for r in range(m)]
    target=int(input())
    print(solve(matrix,target))  
    """
    matrix = [
    [1, 3, 9],
    [2, 5, 10],
    [5, 7, 13]
]
target = 7 
print(solve(matrix,target))      