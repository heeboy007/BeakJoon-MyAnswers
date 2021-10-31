
t = int(input())

for t in range(t):
    n, m = [int(x) for x in input().split(' ')]
    cnt = 1
    while(n > 1):
        n //= 2
        cnt += 1
    cnt += m
    print(cnt)
    