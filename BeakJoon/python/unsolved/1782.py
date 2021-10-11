
class Mirror:

    def __init__(self, start = 1):
        self.temp = (0, 1, 4)
        self.to = [0, 1, 2, 5, 8]
        self.opp = [0, 1, 5, 2, 8]
        self.lowest = [0, 1, 2, 2, 2, 3, 3, 3, 4, 4]
        self.phase = 0
        self.curr = []
        self.start = start
        self.ans = [3, 4]
        for x in range(2, 18):
            if(x % 2 == 0):
                self.ans.append(self.ans[x - 1] * 3)
            else:
                self.ans.append(self.ans[x - 2] * 5)

    def to_i(self):
        output = 0
        for i in range(len(self.curr)):
            output *= 10
            output += self.curr[i]
        yield output

    def loop(self, depth, n):
        for x in range(5):
            if depth == n - 1 and self.phase % 2 == 1 and (x == 2 or x == 3):
                continue
            self.curr[depth] = self.to[x]
            self.curr[self.phase - 1 - depth] = self.opp[x]
            if depth < n - 1:
                yield from  self.loop(depth + 1, n)
            else:
                yield from  self.to_i()

    def __iter__(self):
        phase = self.start
        self.phase = phase
        self.curr = [0] * phase
        for x in range(1, 5):
            self.curr[0] = self.to[x]
            self.curr[phase - 1] = self.opp[x]
            if phase != 2:
                yield from self.loop(1, (phase + phase % 2) // 2)
            else:
                yield from self.to_i()

a, b = input().split(' ')
la = len(a)
lb = len(b)
ia = int(a)
ib = int(b)
