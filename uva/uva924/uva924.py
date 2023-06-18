import io, os
from itertools import repeat
from collections import deque
import sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

e = int(input())
adj = []

for _ in repeat(None, e):
    adj.append(list(map(int, input().strip().split()[1:])))

t = int(input())

for _ in repeat(None, t):
    q = deque([])
    erpd = [(0, -1)] * e
    visited = [False] * e
    s = int(input())
    q.append((s,0))
    visited[s] = True
    while q:
        u = q.popleft()
        d = u[1]
        d1 = u[1] + 1
        for v in adj[u[0]]:
            if not visited[v]:
                q.append((v, d1))
                visited[v] = True
                erpd[d1] = (erpd[d1][0] + 1, d1)
    erpd = sorted(erpd, key = lambda x: (-x[0], x[1]))
    if erpd[0][0] == 0:
        sys.stdout.write(str(0) + '\n')
    else:
        sys.stdout.write(str(erpd[0][0]) + ' ' + str(erpd[0][1]) + '\n')




