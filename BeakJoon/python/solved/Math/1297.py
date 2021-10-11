import math

d, w, h = [int(x) for x in input().split(' ')]

x = math.sqrt(d ** 2 / (h ** 2 + w ** 2))

print(math.floor(x * w), math.floor(x * h))