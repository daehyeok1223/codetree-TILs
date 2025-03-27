n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def find_min():
    pass

def dfs(i, j, m):
    global ans
    if ans >= grid[i][j]:
        return

    m = min(m, grid[i][j])
    if i == n-1 and j == n-1:
        ans = max(ans, m)
        return

    if i+1 < n: dfs(i+1, j, m)
    if j+1 < n: dfs(i, j+1, m)

ans = 0
dfs(0, 0, 1000000)
print(ans)