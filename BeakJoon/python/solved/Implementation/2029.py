
match_list_hor = []
match_list_ver = []

for x in range(10):
    match_info = input()
    if(x % 3 == 0):
        match_list_hor.append((match_info[1] == '-', match_info[4] == '-', match_info[7] == '-'))
    elif(x % 3 == 1):
        match_list_ver.append((match_info[0] == '|', match_info[3] == '|', match_info[6] == '|', match_info[9] == '|'))

match_list_hor = tuple(match_list_hor)
match_list_ver = tuple(match_list_ver)

#print(match_list_hor)
#print(match_list_ver)

match_num = 0
for match_node in match_list_hor:
    for match in match_node:
        if not match:
            match_num += 1
for match_node in match_list_ver:
    for match in match_node:
        if not match:
            match_num += 1

square_num = 0
for x in range(3):
    for y in range(3):
        if match_list_hor[x][y] and match_list_hor[x + 1][y] and match_list_ver[x][y] and match_list_ver[x][y + 1]:
            square_num += 1

for x in range(2):
    for y in range(2):
        if match_list_hor[x][y] and match_list_hor[x + 2][y] \
        and match_list_ver[x][y] and match_list_ver[x][y + 2] \
        and match_list_hor[x][y + 1] and match_list_hor[x + 2][y + 1] \
        and match_list_ver[x + 1][y] and match_list_ver[x + 1][y + 2]:
            square_num += 1

if match_list_hor[0][0] and match_list_hor[0][1] and match_list_hor[0][2] and \
    match_list_hor[3][0] and match_list_hor[3][1] and match_list_hor[3][2] and \
    match_list_ver[0][0] and match_list_ver[0][3] and match_list_ver[1][0] and \
    match_list_ver[1][3] and match_list_ver[2][0] and match_list_ver[2][3]:
    square_num += 1

print(match_num, square_num)