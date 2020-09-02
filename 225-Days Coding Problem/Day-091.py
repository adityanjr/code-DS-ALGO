# it will print 9 , as first for loop exit at 9 
# so 'i' will have value 9 at the end of for loop & all lambda function use 
# i as their return value
functions = []
for i in range(10):
    functions.append(lambda : i)
i = 0
for f in functions:
    print(f())
    i = i + 1
