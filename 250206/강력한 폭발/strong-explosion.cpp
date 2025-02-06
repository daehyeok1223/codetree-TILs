#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[20][20];  // 초기 폭탄 배치 상태
int max_destroyed = 0;  // 최대 초토화된 칸의 수

vector<pair<int, int>> bomb_pos;  // 폭탄을 놓을 수 있는 위치

// 폭탄 종류 1: 세로 방향 폭발
void Bump_1(int x, int y, int backup[20][20]) {
    for (int i = -2; i <= 2; i++) {
        int nx = x + i;
        if (nx >= 0 && nx < n) {
            backup[nx][y] = 1;  // 폭발 표시
        }
    }
}

// 폭탄 종류 2: 십자 방향 폭발
void Bump_2(int x, int y, int backup[20][20]) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            backup[nx][ny] = 1;
        }
    }
    backup[x][y] = 1;  // 폭탄 중심도 포함
}

// 폭탄 종류 3: 대각선 방향 폭발
void Bump_3(int x, int y, int backup[20][20]) {
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            backup[nx][ny] = 1;
        }
    }
    backup[x][y] = 1;  // 폭탄 중심도 포함
}

// 초토화된 칸의 수를 계산하는 함수
int CalcDestroyed(int backup[20][20]) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (backup[i][j] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

// 백트래킹으로 폭탄을 배치하는 함수
void Backtracking(int cnt) {
    if (cnt == bomb_pos.size()) {  // 모든 폭탄 배치 완료
        int backup[20][20] = {0};  // 현재 폭발 상태를 저장할 배열

        for (int i = 0; i < bomb_pos.size(); i++) {
            int x = bomb_pos[i].first;
            int y = bomb_pos[i].second;
            int bomb_type = grid[x][y];  // 해당 위치의 폭탄 타입에 따라 폭발

            if (bomb_type == 1) {
                Bump_1(x, y, backup);
            } else if (bomb_type == 2) {
                Bump_2(x, y, backup);
            } else if (bomb_type == 3) {
                Bump_3(x, y, backup);
            }
        }

        // 초토화된 칸의 수 계산 및 최대값 갱신
        max_destroyed = max(max_destroyed, CalcDestroyed(backup));
        return;
    }

    // 현재 폭탄 위치에 1, 2, 3번 폭탄을 배치하고 백트래킹
    for (int i = 1; i <= 3; i++) {
        int x = bomb_pos[cnt].first;
        int y = bomb_pos[cnt].second;

        grid[x][y] = i;  // 폭탄 타입 배치
        Backtracking(cnt + 1);
        grid[x][y] = 0;  // 원래 상태로 되돌림 (백트래킹)
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int bomb_place;
            cin >> bomb_place;
            if (bomb_place == 1) {
                bomb_pos.push_back({i, j});
            }
        }
    }

    // 폭탄 배치와 최대 초토화 계산 시작
    Backtracking(0);
    cout << max_destroyed << endl;
    return 0;
}
