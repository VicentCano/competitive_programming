from itertools import repeat
from collections import deque

while True:
    n = int(input())
    if n == 0:
        exit(0)
    l = int(input())

    visited = [False] * n
    color = [-1] * n
    adj = [[] for i in repeat(None, n)]

    for i in range(l):
        a, b = input().strip().split()
        a = int(a)
        b = int(b)

        adj[a].append(b)
        adj[b].append(a)

   
    color[0] = 0
    isBi = True
    q = deque()
    q.append(0)
    while q and isBi:
        u = q.popleft()
        for v in adj[u]:
            if color[v] == -1:
                color[v] = abs(color[u] -1)
                q.append(v)
            elif color[v] == color[u]:
                isBi = False
                break
    
    if isBi:
        print("BICOLORABLE.")
    else:
        print("NOT BICOLORABLE.")
