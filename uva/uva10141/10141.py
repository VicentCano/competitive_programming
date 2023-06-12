case = 0
n, p = input().strip().split()
while True:
    n = int(n)
    p = int(p)
    max_c = 0
    min_price = float('inf')
    best = ''
    r = []
    for i in range(n):
        r.append(input())
    
    for i in range(p):
        brand = input()
        price, mr = input().strip().split()
        price = float(price)
        mr = int(mr)
        if best == '' or mr/n > max_c or (mr/n == max_c and price < min_price):
            max_c = mr/n
            min_price = price
            best = brand
        for j in range(mr):
            input()
    case += 1
    print(f'RFP #{case}')
    print(best)
    n, p = input().strip().split()
    if n == '0' and p == '0':
        exit(0)
    print()
