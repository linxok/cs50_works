import sys

if not(len(sys.argv) == 2):
    print("Erorr\n")
    exit(1)
    
if not(sys.argv[1].isalpha()):
    print("Erorr\n")
    exit(1)

text = input("plaintext: ")
c = ''
k = 0

def caesar (c,key):
    if(c.isalpha()): 
        if (c.isupper()):
            c = chr(((ord(c)-ord('A')+key)%26)+ord('A'))
        else:
            c = chr(((ord(c)-ord('a')+key)%26)+ord('a'))
    return c    


print("ciphertext: ", end = '')

for i in range(len(text)):
    if sys.argv[1][k].isupper():
        key = (ord(sys.argv[1][k]) - ord('A'))
    else:
        key = (ord(sys.argv[1][k]) - ord('a'))
        
    print (caesar(text[i],key), end='')
    k+=1
    if k >= len(sys.argv[1]):
        k = 0
    
print()