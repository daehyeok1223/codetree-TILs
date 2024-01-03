#include <iostream>
using namespace std;

void Print(int a, int b) {
    int cnt = 0;

    for (int i = a; i < b + 1; i++) {
        int IsPrime = 1;
        for (int j = 2;j < i;j++) {
            if (i % j == 0) {
                IsPrime = 0;
                break;
            }
        }

        if (IsPrime == 1 && (i / 10 + i % 10) % 2 == 0) cnt++;
    }
    cout << cnt;
  
}
int main() {
    int a, b;
    cin >> a >> b;
    Print(a, b);
    return 0;
}