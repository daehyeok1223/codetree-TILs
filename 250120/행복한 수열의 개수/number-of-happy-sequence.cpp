#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[100][100];
int index[101];

int main() {
    cin >> n >> m;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                index[grid[i][j]]++;
            }
            else {
                if (grid[i][j - 1] == grid[i][j]) {
                    index[grid[i][j]]++;
                }
                else {
                    index[grid[i][j]] = 0;
                    index[grid[i][j]]++;
                }
            }
        }
        int temp = 0;
        for (int k = 0; k <= 100; k++) {
            if (temp < index[k]) {
                temp = index[k];
            }
        }
        if (temp >= m) {
            ans++;
        }
        
        fill(index, index + 101, 0);
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                index[grid[i][j]]++;
            }
            else {
                if (grid[i - 1][j] == grid[i][j]) {
                    index[grid[i][j]]++;
                }
                else {
                    index[grid[i][j]] = 0;
                    index[grid[i][j]]++;
                }

            }
        }
        int temp = 0;
        for (int k = 0; k <= 100; k++) {
            if (temp < index[k]) {
                temp = index[k];
            }
        }
        if (temp >= m) {
            ans++;
        }
        fill(index, index + 101, 0);

    }
    
    cout << ans;
    return 0;
}
