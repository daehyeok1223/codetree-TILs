#include <iostream>
using namespace std;

string CheckCommonElements(int n1, int n2, int A[], int B[]) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                int k;
                for (k = 0; k < n2; k++) {
                    if (i + k >= n1 || j + k >= n2 || A[i + k] != B[j + k]) {
                        break;
                    }
                }
                if (k == n2) {
                    return "Yes";  // 공통 부분이 발견되었을 때 "yes" 반환
                }
            }
        }
    }

    return "No";  // 공통 부분이 없을 때 "no" 반환
}

int main() {
    int A[100];
    int B[100];
    int n1, n2;
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n2; i++) {
        cin >> B[i];
    }

    cout << CheckCommonElements(n1, n2, A, B) << endl;

    return 0;
}