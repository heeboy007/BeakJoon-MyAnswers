

n = int(input())
adj = [[int(x) for x in input().split(' ')] for y in range(n)]
is_visited = [0] * n
result_map = []

def dfs(index):
    for i in range(n):
        if(is_visited[i] == 0 and adj[index][i] == 1):
            is_visited[i] = 1
            dfs(i)

for i in range(n):
    dfs(i)
    result_map.append(is_visited)
    for x in is_visited:
        print(x, end=' ')
    print()
    is_visited = [0] * n