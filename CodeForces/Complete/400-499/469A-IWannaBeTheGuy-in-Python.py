#Question link : http://codeforces.com/contest/469/problem/A

num = int(input())
X = list(map(int, input().split()))
lx = X[0]
X.pop(0)
X.sort()
Y = list(map(int, input().split()))
ly = Y[0]
Y.pop(0)
Y.sort()
i = j = p = q = t = 0
for x in range(1, num+1):
    p, q = i, j
    if i<lx:
        if X[i] == x:
            i += 1
    if j<ly:
        if Y[j] == x:
            j += 1
    if p==i and q==j:
        t = 1
        break
if t==1:
    print("Oh, my keyboard!")
else:
    print("I become the guy.")
    
#End of Program
