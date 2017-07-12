while True:
    cardnum = int(input("Please give me your Credit Card Number :D "))
    if int(cardnum) > 0:
        break

aux = 0
aux2 = 0
acc = 2
lengthcard = len(str(cardnum))

#code = (cardnum % (10**acc))#print(code)
#code = code // (10**(acc-1))#print(code)
#code = 2 * code#print(code)
#aux += sum(int(digit) for digit in str(code))
#print(aux)
#code = 2 * ((cardnum % (10**acc)) // (10**(acc-1)))
#print(code)
#aux += sum(int(digit) for digit in str(code))
#print(aux)
#exit(1)


# the even positions to duplicate and sum its digits
for i in range(lengthcard//2!=0):
    code = 2 * ((cardnum % (10**acc)) // (10**(acc-1)))
    aux += sum(int(digit) for digit in str(code))
    acc = acc + 2

#the odd numbers just to sum them
acc=1
for i in range(lengthcard//2!=0):
    aux += ((cardnum % (10**acc)) // (10**(acc-1)))
    acc = acc + 2
    
print(aux)