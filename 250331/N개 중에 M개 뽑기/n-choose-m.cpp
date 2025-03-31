#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

void Print(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << '\n';
}

void backtracking(int cnt, int start) { // start: 선택 가능한 최소 값
    if(cnt == M){
        Print();
        return;
    }
    for(int i = start; i <= N; i++){
        v.push_back(i);
        backtracking(cnt + 1, i + 1); // i 이후의 숫자들만 선택
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    backtracking(0, 1); // 초기 호출 시, cnt는 0, start는 1
    return 0;
}
