from itertools import repeat
from collections import deque
t = int(input())


for i in range(t):
    n = int(input())
    if n == 0:
        print(f'Case {i+1}: 0')
        continue
    g = []
    visited = [[False] * n for i in repeat(None, n)]
    for j in range(n):
        l = input().strip()
        g.append([*l])
    ships = 0
    for j in range(n):
        for k in range(n):
            if g[j][k] != '.' and not visited[j][k]:
                alive = False
                q = deque()
                q.append((j,k))
                while q:
                    u = q.popleft()
                    visited[u[0]][u[1]] = True
                    if g[u[0]][u[1]] == "x" and not alive:
                        ships += 1
                        alive = True
                    if u[0] > 1:
                        if g[u[0]-1][u[1]] != '.' and not visited[u[0]-1][u[1]]:
                            q.append((u[0] - 1, u[1]))
                    if u[1] > 1:
                        if g[u[0]][u[1] - 1] != '.' and not visited[u[0]][u[1] - 1]:
                            q.append((u[0], u[1] - 1))
                    if u[0] < n - 1:
                        if g[u[0] + 1][u[1]] != '.' and not visited[u[0] + 1][u[1]]:
                            q.append((u[0] + 1, u[1]))
                    if u[1] < n - 1:
                        if g[u[0]][u[1] + 1] != '.' and not visited[u[0]][u[1] + 1]:
                            q.append((u[0], u[1] + 1))
   
    print(f'Case {i+1}: {ships}')