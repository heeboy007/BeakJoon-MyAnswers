mod = 1000000

n = int(input())
unt = 15 * mod // 10

li = [0, 1]
for i in range(2, unt):
    li.append(li[i - 1] + li[i - 2])
    li[i] %= mod
    
print(li[n % unt])