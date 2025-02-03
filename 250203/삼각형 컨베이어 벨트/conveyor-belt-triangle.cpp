#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;
    int temp1,temp2,temp3;


    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    for(int i = 0; i < t; i++){
        temp1 = l[n - 1];
        temp2 = r[n - 1];
        temp3 = d[n - 1];
        for(int j = n - 1; j > 0; j--){
            l[j] = l[j - 1];
            r[j] = r[j - 1];
            d[j] = d[j - 1];
        }
        l[0] = temp3;
        r[0] = temp1;
        d[0] = temp2;
    }

    for (int i = 0; i < n; i++) cout << l[i] << " ";
    cout<<'\n';
    for (int i = 0; i < n; i++) cout << r[i] << " ";
    cout<<'\n';
    for (int i = 0; i < n; i++) cout << d[i] << " ";

    return 0;
}
