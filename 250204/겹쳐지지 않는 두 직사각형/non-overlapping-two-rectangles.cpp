#include <iostream>

using namespace std;

int n, m;
int grid[5][5];
int board[5][5];

void Clear(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            board[i][j] = 0;
        }
    }
}//직사각형이 겹치는 것을 확인하기 위한 보드 초기화

void Draw(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            board[i][j]++;
        }
    }
}//겹치는 곳을 체크하기 위한 보드 계산

bool CheckBoard(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] >= 2){
                return true;
            }
        }
    }
    return false;
}//겹치는 직사각형이 있나 확인하기

bool overlap(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){
    Clear();
    Draw(x1,y1,x2,y2);
    Draw(x3,y3,x4,y4);
    return CheckBoard();
}

int RectSum(int x1, int y1, int x2, int y2){
    int sum = 0;
    for(int i = x1; i <=x2; i++){
        for(int j = y1; j <= y2; j++){
            sum+=grid[i][j];
        }
    }
    return sum;
}

int FindMaxSum(int x1, int x2, int y1, int y2){
    int max_sum = -10000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < m; l++){
                    if(!overlap(x1,x2,i,k,y1,y2,j,l)){
                        max_sum = max(max_sum, RectSum(x1,y1,x2,y2) + RectSum(i,j,k,l));
                    }
                }
            }
        }
    }
    return max_sum;
}

int FindMaxSum(){
    int max_sum = -10000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < m; l++){
                   max_sum = max(max_sum, FindMaxSum(i,k,j,l));
                }
            }
        }
    }
    return max_sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = FindMaxSum();
    cout<<ans;

    return 0;
}
