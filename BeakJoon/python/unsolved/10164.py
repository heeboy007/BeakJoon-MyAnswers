import math

def ways(a, b):
    return math.factorial(a + b) // math.factorial(a) // math.factorial(b)

n, m, k = [int(x) for x in input().split(' ')]

if k != 0:
    x = (k - 1) // m + 1
    y = (k - 1) % m + 1
    print(ways(n - x, m - y) * ways(x - 1, y - 1))
else:
    print(ways(n - 1, m - 1))
