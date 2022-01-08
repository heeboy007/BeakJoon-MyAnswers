
start = input()
n = len(start)
lol = []

for x in range(0, n):
    lol.append(start[x : n])

lol.sort()

for s in lol:
    print(s)