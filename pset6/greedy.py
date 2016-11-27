import cs50
print ("O hai!", end=" ")
cash= 0.0
while cash<= 0:
    print ("How much change is owed?", end="")
    cash = cs50.get_float()
coin = 0
cash = round (cash * 100)

while cash > 0:
    if cash >= 25:
        cash -= 25
        coin += 1
    elif cash >= 10:
        cash -= 10
        coin += 1
    elif cash >= 5:
        cash -= 5
        coin += 1
    elif cash >= 1:
        cash -= 1
        coin += 1
        
print (coin)
