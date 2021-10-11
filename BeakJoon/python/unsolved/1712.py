import math

a, b, c = [int(x) for x in input().split(' ')]

if(c <= b):
    print(-1)
else:
    print(math.floor(a / (c - b)) + 1)