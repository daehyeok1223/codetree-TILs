#include <iostream>
#include <cmath>

using namespace std;

int n;
int arr[50];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cout<<abs(arr[i])<<" ";
    }

    

    return 0;
}