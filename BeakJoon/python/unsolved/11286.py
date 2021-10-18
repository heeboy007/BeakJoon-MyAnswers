from heapq import *

n = int(input())
pq = []
res = []

for i in range(n):
    x = int(input())
    if(x == 0):
        if(len(pq) == 0):
            res.append("0\n")
        else:
            res.append(f"{heappop(pq)[1]}\n")
    else:
        heappush(pq, (x if x > 0 else -x, x))

print("".join(res))