
end_number_list = []
index = 666

while len(end_number_list) <= 10000:
    if "666" in str(index):
        end_number_list.append(index)
    index += 1

for i in range(10000):
    print(end_number_list[i])
