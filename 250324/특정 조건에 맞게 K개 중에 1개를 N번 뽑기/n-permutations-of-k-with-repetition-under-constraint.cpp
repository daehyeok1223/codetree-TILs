#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> selected_nums;

// 선택된 원소들을 출력해줍니다.
void PrintPermutation() {
    for(int i = 0; i < (int) selected_nums.size(); i++)
        cout << selected_nums[i] << " ";
    cout << endl;
}

void FindConditionalPermutation(int cnt) {
    // n개를 모두 뽑은 경우 답을 출력해줍니다.
    if(cnt == n) {
        PrintPermutation();
        return;
    }

    for(int i = 1; i <= k; i++) {
        if(cnt >= 2 && i == selected_nums[cnt - 1] &&
                i == selected_nums[cnt - 2]) 
            continue;
        else {
            selected_nums.push_back(i);
            FindConditionalPermutation(cnt + 1);
            selected_nums.pop_back();
        }
    }
}

int main() { 
    cin >> k >> n;

    FindConditionalPermutation(0);
    return 0;
}
