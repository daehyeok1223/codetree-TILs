#include <iostream>

using namespace std;

int a, b;
void Cal(){
    if(a > b){
        b += 10;
        a *= 2;
    }
    else{
        a += 10;
        b *= 2;
    }
}

int main() {
    cin >> a >> b;

    Cal();
    cout<<a<<" "<<b;

    return 0;
}