n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def dfs(i, j, m):
    global ans, v
    if grid[i][j] <= ans:
        return

    if m <= v[i][j]:
        return

    m = min(m, grid[i][j])
    if i == n-1 and j == n-1:
        ans = max(ans, m)
        return

    if i+1 < n:
        dfs(i+1, j, m)
        v[i+1][j] = ans
    if j+1 < n:
        dfs(i, j+1, m)
        v[i][j+1] = ans

ans = 0
v = [[-1] * n for _ in range(n)]
dfs(0, 0, 1000000)
print(ans)