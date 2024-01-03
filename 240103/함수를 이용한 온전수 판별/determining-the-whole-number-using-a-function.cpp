#include <iostream>
using namespace std;

void Print(int a, int b) {
    int cnt = 0;
    for (int i = a;i < b + 1;i++) {
        if (i % 2 != 0 && i % 5 != 0 && i % 3 != 0) {
            cnt++;
        }
        else if (i % 2 != 0 && i % 5 != 0 && i % 9 == 0) {
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    int a, b;
    cin >> a >> b;
    Print(a, b);
    return 0;
}