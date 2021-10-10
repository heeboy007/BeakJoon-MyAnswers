
def full(digit):
    if(digit == 1):
        return 3
    mid = digit // 2 - 1
    return (5 ** mid) * 4 * (3 if digit % 2 == 1 else 1)

def limit(x, depth, is_limited):
    if(is_limited):
        if depth == 0:
            mirror = (1, 2, 5, 8)
        elif len(x) % 2 == 1 and len(x) // 2 == depth:
            mirror = (0, 1, 8)
        else:
            mirror = (0, 1, 2, 5, 8)
        if(len(x) // 2 == depth):
            count = 0
            for m in mirror:
                if m <= x[depth]:
                    count += 1
            return count
        else:
            result = 0
            count = 0
            for m in mirror:
                if m < x[depth]:
                    count += 1
                elif m == x[depth]:
                    result += limit(x, depth + 1, True)
            result += limit(x, depth + 1, False) * count
            return result
    else:
        return (5 ** (len(x) // 2 - depth)) * (3 if len(x) % 2 == 1 else 1)

def ans(x):
    result = 0
    for i in range(len(x) - 1):
        result += full(i)
    return result + limit(x, 0, True)

a, b = input().split(' ')
a = [int(x) for x in a]
b = [int(x) for x in b]

print(ans(b))