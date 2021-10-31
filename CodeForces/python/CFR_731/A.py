
x = int(input())

for i in range(x):
    s = input()
    for c in "abcdefghijklmnopqrstuvwxyz":
        if(s.find(c) != -1):
            print(c, s.replace(c, '', 1))
            break