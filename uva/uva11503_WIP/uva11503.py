import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

class UF:
    def __init__(self, n):
        self.p = list(range(n))
        self.rank = [0] * n

    def findSet(self, i):
        if self.p[i] == i:
            return i
        else:
            self.p[i] = self.findSet(p[i])
            return self/self.p[i]
    def isSameSet(self, i, j):
        return self.findSet(self.p, i) == self.findSet(self.p, j)
    def unionSet(self, i, j):
        if not self.isSameSet(self.p, i, j):
            x = self.findSet(self.p, i)
            y = self.findSet(self.p, j)
            if self.rank[x] > self.rank[y]:
                self.p[y] = x
                self.p[x] = y
                if (self.rank[x] == self.rank[y]):
                    self.rank[y] += 1
    def __str__(self):
        return f'p:{self.p}\nrank:{self.rank}\n'

friends = UF(7)
print(friends)
