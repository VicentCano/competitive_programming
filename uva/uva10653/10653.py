from itertools import repeat
from collections import deque

while True:
    r, c = input().strip().split()
    if r == '0':
        exit(0)
    r = int(r)
    c = int(c)

    br = int(input())

    bombs = [[False] * c for i in repeat(None, r)]
    visited = [[False] * c for i in repeat(None, r)]

    for i in range(br):
        l = input().strip().split()
        for bc in l[2:]:
            bombs[int(l[0])][int(bc)] = True
    sx, sy = input().strip().split()
    sx = int(sx)
    sy = int(sy)
    fx, fy = input().strip().split()
    fx = int(fx)
    fy = int(fy)

    q = deque()
    q.append((sx, sy, 0))
    sd = 0
    while q:
        u = q.popleft()
        sd = u[2]
        visited[u[0]][u[1]] = True
        if u[0] > 1 and not visited[u[0] - 1][u[1]] and not bombs[u[0] - 1][u[1]]:
            q.append((u[0] - 1, u[1], u[2] + 1))
        if u[1] > 1 and not visited[u[0]][u[1] - 1] and not bombs[u[0] - 1][u[1]]:
            q.append((u[0], u[1] - 1, u[2] + 1))
        if u[1] < c - 1 and not visited[u[0]][u[1] + 1] and not bombs[u[0] - 1][u[1]]:
            q.append((u[0], u[1] + 1, u[2] + 1))
        if u[0] < r - 1 and not visited[u[0] + 1][u[1]] and not bombs[u[0] - 1][u[1]]:
            q.append((u[0] + 1, u[1], u[2] + 1))

    print(sd)