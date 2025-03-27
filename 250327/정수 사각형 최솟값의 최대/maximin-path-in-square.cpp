#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // 입력
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    // 초기값
    dp[0][0] = grid[0][0];

    // 첫 행
    for (int j = 1; j < N; ++j)
        dp[0][j] = min(dp[0][j - 1], grid[0][j]);

    // 첫 열
    for (int i = 1; i < N; ++i)
        dp[i][0] = min(dp[i - 1][0], grid[i][0]);

    // 나머지 dp
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            int from_up = min(dp[i - 1][j], grid[i][j]);
            int from_left = min(dp[i][j - 1], grid[i][j]);
            dp[i][j] = max(from_up, from_left);
        }
    }

    cout << dp[N - 1][N - 1] << endl;
    return 0;
}
