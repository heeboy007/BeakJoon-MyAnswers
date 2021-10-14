
h, w = [int(x) for x in input().split(' ')]
c = int(input())

h += (w + c) // 60
w = (w + c) % 60
h %= 24

print(h, w)