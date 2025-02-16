#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX 15

using namespace std;

int n;
pair<int, int> seg[MAX]; // pair을 사용할 때  MAX처럼 최대 배열 개수를 써줘야함.
int ans;
vector<pair<int,int>> selected_seg;

bool overlapped(pair<int, int> seg1, pair<int,int> seg2){
    int ax1, ax2;
    tie(ax1, ax2) = seg1;//seg값을 ax1,2,에 할당
    int bx1, bx2;
    tie(bx1, bx2) = seg2;
    return (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) ||
        (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
}// 두 개의 선분이 있을 때 겹치는 지 안겹치는 지 판단하는 함수.

bool Possible(){
    for(int i = 0; i < selected_seg.size(); i++){
        for(int j = i + 1; j < selected_seg.size(); j++){
            if(overlapped(selected_seg[i], selected_seg[j])){
                return false;
            }
        }
    }
    return true;
}//seg안에 들어있는 모든 값들을 비교하면서 겹치면 false를 반환한다.

void FindMaxSegments(int cnt){
    if(cnt == n){
        if(Possible()){
            ans = max(ans, (int)selected_seg.size());
        }
        return;
    }
    selected_seg.push_back(seg[cnt]);
    FindMaxSegments(cnt + 1);//seg[cnt]를 선택하는 경우
    selected_seg.pop_back();
    FindMaxSegments(cnt + 1);//seg[cnt]를 선택하지 않는 경우
}//결국 조합의 핵심은 


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        seg[i] = make_pair(x1, x2);
    }
    FindMaxSegments(0);

    cout <<  ans;

    return 0;
}
