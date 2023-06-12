l = input()
while(l != "0"):
    d = "+x"
    l = input().split(" ")
    for d1 in l:
        if d == "+x":
            if d1 != "No":
                d = d1
        elif d == "-x":
            if d1 != "No":
                if d1[0] == "+":
                    d = "-" + d1[1]
                else:
                    d = "+" + d1[1]
        elif d == "+y":
            if d1[1] == "y":
                if d1[0] == "+":
                    d = "-x"
                else:
                    d = "+x"
        elif d == "-y":
            if d1[1] == "y":
                if d1[0] == "+":
                    d = "+x"
                else:
                    d = "-x"
        elif d == "+z":
            if d1[1] == "z":
                if d1[0] == "+":
                    d = "-x"
                else:
                    d = "+x"
        elif d == "-z":
            if d1[1] == "z":
                if d1[0] == "+":
                    d = "+x"
                else:
                    d = "-x"
    print(d)
    l = input()
