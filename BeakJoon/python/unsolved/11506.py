from sys import stdin

length = 0

while True:
    try:
        length += len(input()) // 3
    except:
        break
    
print("��" * length , end="")