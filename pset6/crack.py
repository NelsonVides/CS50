import sys
import crypt

if len(sys.argv) != 2:      #//sanity check for umproper prompt line
    print("Usage: ./crack hasz\n")
    exit(1)

if len(sys.argv[1]) != 13:   #sanity check for improper hasz
    print("Not a DES hasz\n")
    exit(1)

# create salt
salt = str(sys.argv[1][:2])

# create hasz
hasz = str(sys.argv[1])

#create word
word=''
listilla = ['','','',''] 

#the characters to bucle through in the loop
alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuwxyz'
lenalf = len(alphabet)

# go iterate everywhere
for i in range(lenalf):                     # make the word to test
    listilla[3] = alphabet[i]               # make the word to test
    for j in range(lenalf):                 # make the word to test
        listilla[2] = alphabet[j]           # make the word to test
        for k in range(lenalf):             # make the word to test
            listilla[1] = alphabet[k]       # make the word to test
            for l in range(lenalf):         # make the word to test
                listilla[0] = alphabet[l]   # make the word to test
                
                # tadarataaaan
                if hasz == crypt.crypt(word.join(listilla).strip(), salt):
                    password = word.join(listilla).strip()
                    print(password)
                    exit(0)

#//andi:50.jPgLzVirkc
#//jason:50YHuxoCN9Jkc
#//malan:50QvlJWn2qJGE
#//mzlatkova:50CPlMDLT06yY
#//patrick:50WUNAFdX/yjA
#//rbowden:50fkUxYHbnXGw
#//summer:50C6B0oz0HWzo
#//stelios:50nq4RV/NVU0I
#//wmartin:50vtwu4ujL.Dk
#//zamyla:50i2t3sOSAZtk