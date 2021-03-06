"""
Approach:We are using the Binary search as we cannot search a matrix with more number of rows and columns.Here First we search
every row such that target lies in the bound of a particular row if the target exists in that row then fix that row and apply 
binary search algorithm over that row

"""

def SearchMatrix(matrix,target):
    if(not matrix or not matrix[0]):
        return(False)
    row=0
    for r in range(len(matrix)):
        if(target==matrix[r][0] or target==matrix[r][-1]):
            return(True)
        if(target>matrix[r][0] and target<matrix[r][-1]):
            row=r
            break
    left=0
    right=len(matrix)-1
    while(left<=right):
        mid=(left+right)//2
        if(matrix[row][mid]==target):
            return(True)
        elif(matrix[row][mid]>target):
            right=mid-1
        else:
            left=mid+1
    return(False)
if __name__=="__main__":
    m,n=map(int,input().split())
    matrix=[[int(input()) for c in range(n)]for r in range(m)]
    target=int(input())
    print(SearchMatrix(matrix,target))        
