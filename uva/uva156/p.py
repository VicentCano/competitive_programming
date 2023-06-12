dict = {}
aw = []
pos = 0
while True:
    words = input().strip().split()
    
    if len(words) == 1 and words[0] == '#':
        break
    for w in words:
        aw.append(w)
        w = w.lower()
        key = str(sorted([*w]))
        if key in dict.keys():
            dict[key] = dict[key] + [pos]
        else:
            dict[key] = [pos]
        pos += 1

ap = []
for v in dict.values():
    if len(v) == 1:
        ap = ap + v

for w in sorted([aw[i] for i in ap]):
    print(w)



        
