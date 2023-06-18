import io, os
import sys

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline


while True:
    t = input().strip().split()
    r, c, i = map(int, t)

    if r == 0 and c == 0 and i == 0:
        exit(0)

    grid = []
    pos = (-1,-1)
    h = -1 
    for i in range(r):
        l = [*input().strip()]
        if h < 0:
            for j in range(c):
                lj = l[j]
                if lj == 78:
                    h = 0
                    pos = (i,j)
                elif lj == 76:
                    h = 1
                    pos = (i,j)
                elif lj == 83:
                    h = 2
                    pos = (i,j)
                elif lj == 79:
                    h = 3
                    pos = (i,j)

        grid.append(l)
    path = [*input().strip()]
    stickers = 0
    for i in path:
        #print(i, chr(i))
        if i == 70:
            p0 = pos[0]
            p1 = pos[1]
            if h == 0:
                npos = (p0 - 1, p1)
            elif h == 1:
                npos = (p0, p1 + 1)
            elif h == 2:
                npos = (p0 + 1, p1)
            else:
                npos = (p0, p1 - 1)

            np0 = npos[0]
            np1= npos[1]
            if np0 >= 0 and np1 >= 0 and np0 < r and np1 < c:
                #print(r, c)
                #print(h, npos)
                
                cip = grid[np0][np1]
                #print(cip)
                if cip != 35:
                    pos = npos
                    if cip == 42:
                        grid[pos[0]][pos[1]] = 46
                        stickers += 1
        elif i == 68:
            h = (h+1)%4
        elif i == 69:
            h = (h-1)%4
    sys.stdout.write(str(stickers) + '\n')

