
x, y = [int(i) for i in input().split(' ')]
grid = [[int(i) for i in input()] for j in range(x)]
is_over = False

for s in range(min(x, y) - 1, 0, -1):
    for i in range(len(grid) - s):
        for j in range(len(grid[i]) - s):
            if grid[i][j] == grid[i + s][j] and grid[i + s][j] == grid[i][j + s] and grid[i][j + s] == grid[i + s][j + s]:
                print((s + 1)*(s + 1))
                is_over = True
                break
        if is_over:
            break
    if is_over:
        break

if not is_over:
    print(1)