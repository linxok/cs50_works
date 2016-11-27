height = 0
while height <= 0 or height > 23:
    height = int(input("height: "))
    
hesh = 2

while height > 0:
    print(" " * (height-1), "#" * hesh)
    hesh = hesh + 1
    height = height - 1
