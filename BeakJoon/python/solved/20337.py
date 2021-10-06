
n = int(input())
nums = []

for st_i in input().split(' '):
    nums.append(int(st_i))

print("3")
temp_num = []
temp_index = []
for i in range(n // 4):
    temp_num.append(nums[i])
    temp_index.append(i)

for i in range(1, n // 4 + 1):
    if i not in temp_num:
        temp_num.append(i)
        temp_index.append(nums.index(i))

i = n // 4
while len(temp_num) < n // 2:
    if nums[i] not in temp_num:
        temp_num.append(nums[i])
        temp_index.append(i)
    i += 1

temp_num.sort()
temp_index.sort()

for out in temp_index:
    print(out + 1, end=' ')
print()

for i in range(n // 2):
    nums[temp_index[i]] = temp_num[i]
#cycle 1

temp_num.clear()
temp_index.clear()
for i in range(n // 4, n // 2):
    temp_num.append(nums[i])
    temp_index.append(i)

for i in range(n // 4 + 1, n // 2 + 1):
    if i not in temp_num:
        temp_num.append(i)
        temp_index.append(nums.index(i))

i = n // 2
while len(temp_num) < n // 2:
    if nums[i] not in temp_num:
        temp_num.append(nums[i])
        temp_index.append(i)
    i += 1

temp_num.sort()

for out in temp_index:
    print(out + 1, end=' ')
print()
#cycle 2

for i in range(n // 2 + 1, n + 1):
    print(i, end=' ')
print()
#print()
#cycle 3(just sort rest of them...)