n = int(input())
for i in range(n):
    s,d = input().strip().split()
    s = int(s)
    d = int(d)
    if s < d or (s%2 != d%2):
        print("impossible")
        continue
    
    first = int((d+s)/2)
    second = int(s - (d+s)/2)
    print(f'{max(first, second)} {min(first,second)}')

