
n, m = (int(x) for x in input().split())
cost = {}
group = [[x] for x in range(n)]

for i in range(m):
    inputs = [int(x) for x in input().split()]
    if inputs[0] == 1: #합류
        a, b = inputs[1] - 1, inputs[2] - 1
        group[a] += group[b]
        y = group[a]
        for x in group[b].copy():
            group[x] = y
    else: #지불
        payer = inputs[1] - 1
        pay_group = group[payer]
        dept = inputs[2] // len(pay_group)
        for persons in pay_group:
            if persons == payer:
                continue
            key = (payer, persons)
            rey = (persons, payer)
            if cost.get(key): #내가 진 빚이 있음
                cost[key] -= dept
                if(cost[key] == 0): #서로 진 빛이 상쇄되므로 그냥 장부에서 지움.
                    del cost[key]
            else: #내가 진 빚이 없음
                if cost.get(rey):
                    cost[rey] += dept
                else: #오브젝트 생성
                    cost[rey] = dept

if(len(cost) > n):
    print(-1)
else:
    print(len(cost))
    for k, v in cost.items():
        if(v > 0):
            print(k[0] + 1, k[1] + 1, v)
        else:
            print(k[1] + 1, k[0] + 1, v)
