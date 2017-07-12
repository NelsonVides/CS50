while True:
    cardnum = int(input("Please give me your Credit Card Number :D "))
    if int(cardnum) > 0:
        break

aux = 0
acc = 2
strnum = str(cardnum)
lengthcard = len(strnum)

# the even positions to duplicate and sum its digits
for i in range(0,lengthcard,2): # How many times?
    code = 2 * ((cardnum % (10**acc)) // (10**(acc-1)))
    aux += sum(int(digit) for digit in str(code))
    acc = acc + 2

#the odd numbers just to sum them
acc=1
for i in range(0,lengthcard,2):
    aux += ((cardnum % (10**acc)) // (10**(acc-1)))
    acc = acc + 2

print(aux)

# go check if it has a valid sum
if (aux % 10)!=0:
    print("invalid card number")
    exit(1)

#AMEX
if lengthcard == 15:
    if strnum[:2] == '34' or strnum[:2] == '37':
        print("AMEX")
        exit(0)

#Master Card
if lengthcard == 16:
    if int(strnum[:2]) in range(51,56):
        print("Master Card")
        exit(0)

#VISA
if lengthcard == 13 or lengthcard == 16:
    if strnum[:1] == '4':
        print("VISA")
        exit(0)

#INVALID
print("INVALID")
exit(1)
