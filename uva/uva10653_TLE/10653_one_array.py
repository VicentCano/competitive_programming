from itertools import repeat
from collections import deque
import io, os

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
while True:
    r, c = input().strip().split()
    
    r = int(r)
    if r == 0:
        exit(0)
    c = int(c)

    br = int(input())

    visited = [[False] * c for i in repeat(None, r)] #visited is really added

    rwb = []
    for i in range(br):
        l = input().strip().split()
        l0 = int(l[0])
        rwb.append(l0)
        for bc in l[2:]:
            visited[l0][int(bc)] = True
    sx, sy = input().strip().split()
    sx = int(sx)
    sy = int(sy)
    fx, fy = input().strip().split()
    fx = int(fx)
    fy = int(fy)

    if sx == fx and sy == fy:
        print(0)
        continue
    elif br == 0:
        print(abs(fx - sx) + abs(fy - sy))
        continue
    elif sx == fx and sx not in rwb:
        print(abs(fy - sy))
        continue
    q = deque()
    q.append((sx, sy, 0))
    sd = 0
    while q:
        u = q.popleft()
        sd = u[2]
        sd1 = sd + 1
        if u[0] > 1 and not visited[u[0] - 1][u[1]]:
            if u[0] - 1 == fx and u[1] == fy:
                sd += 1
                break
            visited[u[0] - 1][u[1]] = True
            q.append((u[0] - 1, u[1], sd1))
        if u[1] > 1 and not visited[u[0]][u[1] - 1]:
            if u[0]== fx and u[1] - 1 == fy:
                sd += 1
                break
            visited[u[0]][u[1] - 1] = True
            q.append((u[0], u[1] - 1, sd1))
        if u[1] < c - 1 and not visited[u[0]][u[1] + 1]:
            if u[0] == fx and u[1] + 1 == fy:
                sd += 1
                break
            visited[u[0]][u[1] + 1] = True
            q.append((u[0], u[1] + 1, sd1))
        if u[0] < r - 1 and not visited[u[0] + 1][u[1]]:
            if u[0] + 1 == fx and u[1] == fy:
                sd += 1
                break
            visited[u[0] + 1][u[1]] = True
            q.append((u[0] + 1, u[1], sd1))

    print(sd)