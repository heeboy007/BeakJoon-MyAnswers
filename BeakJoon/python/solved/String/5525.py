
n = int(input())
l = int(input())
s = input() + "XXXX"
ans = []

i = 0
while i < l:
    if(s[i : i + 3] == 'IOI'):
        start = i
        end = i + 3
        while s[end - 1: end + 2] == 'IOI':
            end += 2
        ans.append((end - start - 1) // 2)
        i = end - 2
    i += 1

result = 0
for x in ans:
    result += max(x - n + 1, 0)

print(result)