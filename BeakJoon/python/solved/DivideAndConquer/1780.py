
def divqon(n, paper):
    if len(paper) == 1:
        return (int(paper[0][0] == -1), int(paper[0][0] == 0), int(paper[0][0] == 1))
    else:
        check = paper[0][0]
        flag = False
        for row in paper:
            for elem in row:
                if elem != check:
                    flag = True
                    break
            if flag:
                break
        if flag:
            a, b, c = 0, 0, 0
            x, y, z = 0, 0, 0
            n = n // 3
            for i in range(3):
                for j in range(3):
                    little = paper[n * i: n * (i + 1)]
                    little = [row[n * j: n * (j + 1)] for row in little]
                    x, y, z = divqon(n, little)
                    a += x; b += y; c += z
            return (a, b, c)
        else:
            return (int(check == -1), int(check == 0), int(check == 1))

n = int(input())
paper = [[int(y) for y in input().split(' ')] for x in range(n)]

a, b, c = divqon(n, paper)
print(a)
print(b)
print(c)