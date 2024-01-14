#include <iostream>
using namespace std;

void Weather(int a) {
    if (a == 3 || a == 4 || a == 5) cout << "Spring";
    else if (a == 6 || a == 7 || a == 8) cout << "Summer";
    else if (a == 9 || a == 10 || a == 11) cout << "Fall";
    else if (a == 12 || a == 1 || a == 2) cout << "Winter";
}
bool IsYoon(int a) {
    int condition = 0;
    if (a % 4 == 0) condition = 1;
    else if (a % 100 == 0) condition = 0;
    else if (a % 400 == 0) condition = 1;
    else condition = 0;
    return condition == 1;
}

void IsYear(int a, int b, int c) {
    if (b == 2 && c < 30 && IsYoon(a)) {
        Weather(b);
    }
    else if (b == 2 && c < 29) {
        Weather(b);
    }

    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && c < 32) {
        Weather(b);
    }
    else if ((b == 4 || b == 6 || b == 9 || b == 11) && c < 31) {
        Weather(b);
    }
    else cout<<"-1";
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    IsYear(a, b, c);

    return 0;
}