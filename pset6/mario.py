#import cs50

while True:
    #print("Tell me how many rows you want")
    n = int(input("Tell me how many rows you want: "))
    if n > 0 and n < 23:
        break

for row in range(n):
    print(" " * (n - row - 1), end="")
    print("#" * (row + 2), end="")
    print()