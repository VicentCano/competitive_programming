import itertools

ts = []

def dfs_ts(u):
    visited[u] = True
    for v in adj[u]:
        if not visited[v]:
            dfs_ts(v)
    ts.append(u)

while True:
    n, m = input().strip().split()
    if n == '0' and m == '0':
        exit(0)
    n = int(n)
    m = int(m)

    ts = []
    visited = [False] * (n+1)
    adj = [[] for i in itertools.repeat(None, n+1)]
    for i in range(m):
        a, b = input().strip().split()
        a = int(a)
        b = int(b)
        adj[a].append(b)

    for i in range(1,n+1):
        if visited[i] == False:
            dfs_ts(i)
    ts.reverse()
    for i in range(n):
        if i < n-1:
            print(f'{ts[i]} ', end='')
        else:
            print(ts[i])



