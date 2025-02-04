#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[200][200];
int r, c;

void Bump(int x, int y){
    int k = grid[x][y];
    for(int i = 0; i < k; i++){
        if(x + i < n){
            grid[x + i][y] = 0;
        }
        if(x - i >= 0){
            grid[x - i][y] = 0;
        }
        if(y + i < n){
            grid[x][y + i] = 0;
        }
        if(y - i >= 0){
            grid[x][y - i] = 0;
        }
    }
}//십자가 모양으로 숫자에 맞게 배열을 0으로 만들어줌
void Pull(){
    for(int j = 0; j < n; j++){
        vector<int> v;
        int num_0 = 0;
        int num = 0;
        for(int i = 0; i < n; i++){
            if(grid[i][j] != 0){
                v.push_back(grid[i][j]);
            }
            else{
                num_0++;
            }
        }
        for(int i = 0; i < num_0; i++){
            grid[i][j] = 0;
        }
        for(int i = num_0; i < n; i++){
            grid[i][j] = v[num];
            num++;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    Bump(r - 1, c - 1);
    Pull();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] <<" ";
        }
        cout<<'\n';
    }

    return 0;
}
