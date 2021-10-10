
a, b, c = [int(x) for x in input().split(' ')]

if a == b:
    if b == c:
        print(10000 + a * 1000)
    else:
        print(1000 + a * 100)
else:
    if b == c:
        print(1000 + b * 100)
    else:
        if a == c:
            print(1000 + a * 100)
        else:
            print(max(a, max(b, c)) * 100)