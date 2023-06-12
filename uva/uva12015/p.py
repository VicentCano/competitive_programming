for i in range(int(input())):
    ws = []
    for j in range(10):
        inp = input().strip().split()
        ws.append((inp[0], int(inp[1])))
    ws = sorted(ws, key = lambda x:-x[1])
    max = ws[0][1]
    print(f"Case #{i+1}:")
    print(ws[0][0])
    j = 1
    while ws[j][1] == max:
        print(ws[j][0])
        j += 1
