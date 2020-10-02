#  Question
# Your task is to calculate the number of bit strings of length n.

# For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.


#  link :- https://cses.fi/problemset/task/1617/

#  name : Sweta Snigdha Sahoo
#  author : swetasahoo29

#  solution

n= int(input())
print((2**n) % ((10**9)+7))

# time complexity : O(n^2)
# space complexity : O(n)
