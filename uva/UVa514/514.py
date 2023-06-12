from collections import deque

n = int(input())
while n != 0:
    o = input().split(" ")
    ii = 1
    io = 0
    st = deque()
    if o[0] == "0":
        print()
        n = int(input())
    else:
        while ii <= n:
            st.append(ii)
            ii = ii + 1
            while len(st) > 0 and (st[len(st)-1] == int(o[io])):
                st.pop()
                io = io + 1
        if len(st) == 0:
            print("Yes")
        else:
            print("No")