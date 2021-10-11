
def count(n):
    count = 0
    while n != 0:
        n = n ^ (n & (-n))
        count += 1
    return count

n, k = [int(x) for x in input().split(' ')]

buy = 0
while count(n) - k > 0:
    buy += n & (-n)
    n += n & (-n)

print(buy)