print("### CEASAR CIPHER ###\n\nEnter Text: ", end="")
string = input() # Plain Text
print("Shift: ", end="")
shift = int(input()) # Shift Key
encrypt = ""

## Encryption

for x in string:
    if(ord(x) >= 65 and ord(x) <= 90):
        if((ord(x) + shift) >= 65 and (ord(x) + shift) <= 90):
            encrypt += chr(ord(x) + shift)
        else:
            encrypt += chr(ord(x) + shift - 26)
    elif(ord(x) >= 97 and ord(x) <= 122):
        if((ord(x) + shift) >= 97 and (ord(x) + shift) <= 122):
            encrypt += chr(ord(x) + shift)
        else:
            encrypt += chr(ord(x) + shift - 26)
    else:
        encrypt += x
print("Encrypted: " + encrypt)

## Decryption

decrypt = ""
for x in encrypt:
    if(ord(x) >= 65 and ord(x) <= 90):
        if((ord(x) - shift) >= 65 and (ord(x) - shift) <= 90):
            decrypt += chr(ord(x) - shift)
        else:
            decrypt += chr(ord(x) - shift + 26)
    elif(ord(x) >= 97 and ord(x) <= 122):
        if((ord(x) - shift) >= 97 and (ord(x) - shift) <= 122):
            decrypt += chr(ord(x) - shift)
        else:
            decrypt += chr(ord(x) - shift + 26)
    else:
        decrypt += x
print("Decrypted: " + decrypt)