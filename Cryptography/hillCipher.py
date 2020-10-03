import numpy as np

key = "GYBNQKURP" # input()
matrix = []
message = []

print("### HILL CIPHER ###\n\nPlain Text: ", end="")
plainText = input('Enter 3 letter string: ')
plainText = plainText.upper()
print('Key: ', key, '\n')

def encryptIt(key, plainText):
    answer = []
    temp = []
    answer = list(np.matmul(matrix, message))
    print("Encrypted Text: ", end='')
    for x in range(3):
        temp.append(chr((answer[x]%26)+65))
    print(temp)     
    return (answer)

def inverseThings(matrix):
    temp = np.array(matrix)
    temp = np.linalg.inv(temp)
    return (temp)

def decryptIt(key, encryptedText):
    inverse = inverseThings(matrix)
    answer = []
    answer = list(np.matmul(inverse, encryptedText))
    for x in range(3):
        answer[x] = chr(int(answer[x]%26) + 65)
    return (answer)

def getIndexValue(x):
    return ord(x)-65

count = 0
for x in range(3):
    temp = []
    for y in range(3):
        temp.append(getIndexValue(key[count]))
        count+=1
    matrix.append(temp)
print("Key Matrix: ", matrix)

for x in range(len(plainText)):
    message.append((getIndexValue(plainText[x])))
print("Message: ", message)

encryptedText = encryptIt(key, plainText)
decryptedText = decryptIt(key, encryptedText)
print("Decrypted Text: ", decryptedText)