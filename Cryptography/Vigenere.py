Key = input("Enter the Encryption Key: ")
Key = Key.upper()
Key = Key.replace(' ','')
length = len(Key)

Plaintext = input("Enter the Message: ")
Plaintext = Plaintext.upper()
Plaintext = Plaintext.replace(' ','')

while(length < len(Plaintext)):
    Key = Key + Key
    length = len(Key)
if(len(Plaintext) < len(Key)):
    Key = Key[0 : len(Plaintext)]

# Encryption
CipherText = ''
for i in range(len(Plaintext)):
   CipherText = CipherText + (chr((ord(Plaintext[i])-65+ord(Key[i])-65)%26+65))
print('\nEncrypted Message:\t', CipherText)

# Decryption
DecryptedText = ''
for i in range(len(CipherText)):
   DecryptedText = DecryptedText + (chr((ord(CipherText[i])-65-ord(Key[i])-65)%26+65))
print('Decrypted Message:\t', DecryptedText)