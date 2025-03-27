#include<iostream>
using namespace std;

//1. 이동한 칸이 범위 안에 있는지 확인한다.
//2. 다음으로 이동한 칸이 이전칸보다 큰지 확인한다 => 이전값을 기억해서 비교
//3. 만약 1,2 범위를 만족하면 최댓값을 update하고 dfs를 돈다.

int N;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int grid[10][10];
int direction[10][10];
int ans;

bool InRange(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}//범위 안에 있는지 확인

bool CheckValue(int x, int y, int prev_value){
    return InRange(x,y) && (grid[x][y] > prev_value);
}//다음에 넘어갈 값이 범위 안에 있고 이전 값보다 큰지 확인

void bfs(int x, int y, int cnt){ // => cnt로 항상 최댓값 update하기
    ans = max(ans, cnt); // 최댓값 update
    int d = direction[x][y] - 1;

    for(int i = 0; i < N; i++){
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        if(CheckValue(nx, ny, grid[x][y])){
            bfs(nx, ny, cnt + 1);
        }
    }
}

int main(){
    int x1, y1;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>grid[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> direction[i][j];
        }
    }
    cin >> x1 >> y1;
    bfs(x1 - 1, y1 - 1, 0);

    cout<<ans;
}