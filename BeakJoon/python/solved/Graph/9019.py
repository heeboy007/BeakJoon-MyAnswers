import collections

def bfs(start, answer):
    queue_number = collections.deque([start,])
    queue_track = collections.deque(["",])
    is_visited = [False] * 10000
    is_visited[start] = True
    while(len(queue_number) > 0):
        now = queue_number.popleft()
        res = queue_track.popleft()
        if(now == answer):
            print(res)
            return
        l = now * 10 % 10000 + now // 1000
        r = now % 10 * 1000 + now // 10
        d = 2 * now % 10000
        s = now - 1 if now != 0 else 9999
        if(not is_visited[l]):
            queue_number.append(l)
            queue_track.append(f"{res}L")
            is_visited[l] = True
        if(not is_visited[r]):
            queue_number.append(r)
            queue_track.append(f"{res}R")
            is_visited[r] = True
        if(not is_visited[d]):
            queue_number.append(d)
            queue_track.append(f"{res}D")
            is_visited[d] = True
        if(not is_visited[s]):
            queue_number.append(s)
            queue_track.append(f"{res}S")
            is_visited[s] = True
            
t = int(input())
for i in range(t):
    start, answer = [int(x) for x in input().split(' ')]
    bfs(start, answer)
