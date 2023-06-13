t = int(input())


for i in range(t):
    n = int(input())
    g = []
    for j in range(n):
        l = input().strip()
        g.append([*l])
    print(g)