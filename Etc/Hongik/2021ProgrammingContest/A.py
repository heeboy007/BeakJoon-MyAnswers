
N = int(input())
stu = [int(x) for x in input().split(' ')]
relat, absol = [int(y) for y in input().split(' ')]

cnt = 0
for x in stu:
    if x >= absol:
        cnt += 1

print(N // 10 * relat // 10, cnt)
