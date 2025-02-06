#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int ans;
vector<int> seq;

bool IsBeautiful(){
    for(int i = 0; i < n; i += seq[i]){
        if(i + seq[i] - 1 >= n){
            return false;
        }
        for(int j = i; j < i + seq[i]; j++){
            if(seq[i] != seq[j]){
                return false;
            }
        }
    }
    return true;
}//자릿수가 n개인 숫자가 아름다운지 아닌지 판별하기

void Make_Digit(int cnt){//cnt는 현재 자릿수를 의미한다.
    if(n == cnt){
        if(IsBeautiful()){
            ans++;
        }
        return;
    }
    for(int i = 1; i <= 4; i++){
        seq.push_back(i);
        Make_Digit(cnt + 1);
        seq.pop_back();
    }
}

int main() {
    cin >> n;
    Make_Digit(0);

    cout<<ans;

    return 0;
}
