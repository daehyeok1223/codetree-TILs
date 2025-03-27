n = int(input())
num = [list(map(int, input().split())) for _ in range(n)]
move_dir = [list(map(int, input().split())) for _ in range(n)]
r, c = map(int, input().split())

# Please write your code here.
from collections import deque

d = [
    0,
    [-1, 0], 
    [-1, 1], 
    [0, 1], 
    [1, 1], 
    [1, 0], 
    [1, -1], 
    [0, -1], 
    [-1, -1], 
]

dq = deque([[r-1, c-1]])
v = [[0] * n for _ in range(n)]
ans = 0

while dq:
    x, y = dq.popleft()
    ans = max(ans, v[x][y])
    move = move_dir[x][y]
    dx, dy = d[move][0], d[move][1]
    nx, ny = x + dx, y + dy
    while 0 <= nx < n and 0 <= ny < n:
        if num[x][y] < num[nx][ny] and v[nx][ny] <= v[x][y]:
            dq.append([nx, ny])
            v[nx][ny] = v[x][y] + 1
        nx += dx
        ny += dy

print(ans)