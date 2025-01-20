#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int grid[200][200];

int sol1(){ //ㄴ
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            temp = grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1];
            ans = max(ans, temp);
        }
    }
    return ans;
}

int sol2(){
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < m; j++){
            temp = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
            ans = max(ans, temp);
        }
    }
    return ans;
}

int sol3(){
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 2; j++){
            temp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
            ans = max(ans, temp);
        }
    }
    return ans;
}

int sol4(){
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            temp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j];
            ans = max(ans, temp);
        }
    }
    return ans;
}

int sol5(){
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            temp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1];
            ans = max(ans, temp);
        }
    }
    return ans;
}

int sol6(){
    int ans = 0;
    int temp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            temp = grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1];
            ans = max(ans, temp);
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    v.push_back(sol1());
    v.push_back(sol2());
    v.push_back(sol3());
    v.push_back(sol4());
    v.push_back(sol5());
    v.push_back(sol6());

    sort(v.begin(), v.end());
    cout<<v[5];
    return 0;
}
