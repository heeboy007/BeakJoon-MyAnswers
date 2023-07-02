
def hive(index):
    return (index - 1) * (index) * 3 + 1

key = int(input())
    
if key == 1:
    print(1)
else:
    low = 1
    high = 10000000000
    mid = (low + high) // 2;
    
    while low + 1 < high :
        check = hive(mid)
        if key <= check:
            high = mid
        else:
            low = mid
        mid = (low + high) // 2;
    print(high)
