
h, m, s = [int(x) for x in input().split(' ')]
d = int(input())

s = (s + d) % 60
d = (s + d) // 60
m = (m + d) % 60
d = (m + d) // 60
h = (h + d) % 24

print(h, m, s)