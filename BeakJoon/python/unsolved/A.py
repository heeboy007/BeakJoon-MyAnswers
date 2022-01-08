n = int(input())

sosu = [2, 3, 5, 7]

for i in range(10, 200):
    is_sosu = True
    for x in sosu:
        if x * x > i:
            break
        if i % x == 0:
            is_sosu = False
            break
    if is_sosu:
        sosu.append(i)

whole = [ sosu[i] * sosu[i + 1] for i in range(len(sosu) - 1) ]
prev = 0

for i in whole:
    if n < i:
        print(i)
        break
    prev = i