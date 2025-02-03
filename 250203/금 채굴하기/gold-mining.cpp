#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m;
int grid[20][20];

int GetArea(int k){
    return k * k + (k + 1) * (k + 1); 
}

int GetNumOfGold(int row, int col, int k){
    int num_of_gold = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(row - i) + abs(col - j) <= k){
                num_of_gold += grid[i][j];
            }
        }
    }
    return num_of_gold;
}

int main() {
    int max_gold = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            for(int k = 0; k <= 2*(n-1); k++){
                int num_of_gold = GetNumOfGold(row, col, k);

                if(num_of_gold * m >= GetArea(k)){
                    max_gold = max(max_gold, num_of_gold);
                }
            }
        }
    }
    cout<<max_gold;

    return 0;
}
