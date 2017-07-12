while True:
    #print("Tell me how many rows you want")
    dollars = float(input("How much do I owe you? "))
    if dollars > 0:
        break

cents = int(dollars * 100)
coins = 0;

coins += cents // 25
cents = cents % 25

coins += cents // 10
cents = cents % 10

coins += cents // 5
cents = cents % 5

coins += cents

print(coins)