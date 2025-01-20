#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[100][100];
int index[101];

int main() {
    cin >> n >> m;
    int ans = 0;

    // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 수평 방향 탐색
    for (int i = 0; i < n; i++) {
        fill(index, index + 101, 0);
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                index[grid[i][j]]++;
            }
            else {
                index[grid[i][j]] = 1; // 새로 시작
            }
            temp = max(temp, index[grid[i][j]]);
        }
        if (temp >= m) {
            ans++;
        }
    }

    // 수직 방향 탐색
    for (int j = 0; j < n; j++) {
        fill(index, index + 101, 0);
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                index[grid[i][j]]++;
            }
            else {
                index[grid[i][j]] = 1; // 새로 시작
            }
            temp = max(temp, index[grid[i][j]]);
        }
        if (temp >= m) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
