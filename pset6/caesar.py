import sys

if not(len(sys.argv) == 2):
    print("Erorr\n")
    exit(1)
    
key = int(sys.argv[1])
    
text = input("plaintext: ")


for i in range(len(text)):
    if(text[i].isalpha()): 
        if (text[i].isupper()):
            text = text[0:i] + (chr(((ord(text[i])-ord('A')+key)%26)+ord('A'))) + text[i+1:]
        else:
            text = text[0:i] + (chr(((ord(text[i])-ord('a')+key)%26)+ord('a'))) + text[i+1:]
        

print("ciphertext: ", text)