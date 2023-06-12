n = input()
i = 0
while i < int(n): 
    c=input().split(" ")
    if len(c) > 1:
        c0 = c[0]
        c1 = int(c[1])
        c2 = int(c[2])
        if c0 == "r":
            print(min(c1,c2))
        elif c0 == "k":
            if c1 == 1:
                print(c2)
            elif c2 == 1:
                print(c1)
            elif c1 == 2 and c2 == 2:
                print(4)
            elif (c1 == 2 and c2 == 3) or (c1 == 3 and c2 ==2):
                print(4)
            else:
                print(int((c1*c2)/2)+int((c1*c2)%2))
        elif c0 == "Q":
                print(min(c1,c2))
        elif c0 == "K":
            if c1 == 1  and c2 == 1:
                print(1)
            else:
                print(int(c1/2 + c1%2) * int(c2/2 + c2%2))
        i = i + 1