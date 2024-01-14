#include <iostream>
#include <vector>
using namespace std;

void Divide(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = arr[i] / 2;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n]; // 동적 할당
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Divide(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr; // 동적 할당 해제
    return 0;
}