#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[100][100];
int index[101];

// 연속된 숫자를 확인하는 함수
int countConsecutive(int n, int m, bool isRow) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        fill(index, index + 101, 0);
        int temp = 0;
        for (int j = 0; j < n; j++) {
            int value = isRow ? grid[i][j] : grid[j][i];
            if (j > 0) {
                int prev = isRow ? grid[i][j - 1] : grid[j - 1][i];
                if (value == prev) {
                    index[value]++;
                } else {
                    index[value] = 1; // 새로 시작
                }
            } else {
                index[value] = 1;
            }
            temp = max(temp, index[value]);
        }
        if (temp >= m) {
            result++;
        }
    }
    return result;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    // 수평 방향 탐색
    ans += countConsecutive(n, m, true);

    // 수직 방향 탐색
    ans += countConsecutive(n, m, false);

    cout << ans;
    return 0;
}
