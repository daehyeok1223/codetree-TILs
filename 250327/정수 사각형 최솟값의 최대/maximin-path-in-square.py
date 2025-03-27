n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
dp = [[0] * n for _ in range(n)]
dp[0][0] = grid[0][0]
for i in range(n):
    for j in range(n):
        if i-1 >= 0 and j-1 >= 0:
            dp[i][j] = min(grid[i][j], max(dp[i-1][j], dp[i][j-1]))
        elif i-1 >= 0:
            dp[i][j] = min(grid[i][j], dp[i-1][j])
        elif j-1 >= 0:
            dp[i][j] = min(grid[i][j], dp[i][j-1])

print(dp[n-1][n-1])