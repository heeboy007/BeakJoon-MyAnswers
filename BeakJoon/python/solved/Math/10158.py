
w, h = [int(x) for x in input().split(' ')]
x, y = [int(x) for x in input().split(' ')]
t = int(input())

x += t
y += t

x %= (2 * w)
y %= (2 * h)

if(x > w):
    x = 2 * w - x
if(y > h):
    y = 2 * h - y

print(x, y, end=' ')