from itertools import repeat
import heapq
import io, os

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n = int(input())
for i in range(n):
    n2, m, s, t = map(int, input().strip().split())
    if m == 0:
        print(f'Case #{i+1}: unreachable')
        continue
    adj = [[] for i in repeat(None, n2)]
    total_latency = [float('inf')] * n2
    for j in range(m):
        a, b, w = map(int, input().strip().split())
        adj[a].append((b, w))
        adj[b].append((a, w))
    if len(adj[t]) == 0:
        print(f'Case #{i+1}: unreachable')
        continue
    q = [(0, s)]
    total_latency[s] = 0
    
    while q:
        latency, u = heapq.heappop(q)
        if total_latency[u] < latency:
            continue
        for v in adj[u]:
            cost = latency + v[1]
            if cost < total_latency[v[0]]:

                total_latency[v[0]] = cost
                heapq.heappush(q, (cost, v[0]))        
        if u == t:
            break
    if total_latency[t] == float('inf'):
        print(f'Case #{i+1}: unreachable')      
    else:
        print(f'Case #{i+1}: {total_latency[t]}')


        