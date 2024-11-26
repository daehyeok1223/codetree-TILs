#include <iostream>
using namespace std;

int arr[21][21];
int N;
int k = 0;

int getNumber(int x, int y){
    int cnt = 0;
    for(int i = x; i <= x + 2; i++){
        for(int j = y; j <= y + 2; j++){
            cnt+=arr[i][j];
        }
    } 
    return cnt;
}//3*3 직사격형 모양의 격자에서 탐색

int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i < N; i++){
        for(int j=0; j<N; j++){
            if(i + 2 < N && j + 2 < N){
                int maxi = getNumber(i,j);
                k = max(maxi, k);
            }
        }
    }
    cout<<k;
    return 0;
}