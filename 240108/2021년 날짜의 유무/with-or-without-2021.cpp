#include <iostream>
using namespace std;

void Print(int a, int b){
    if(a==2&&b<29){
        cout<<"Yes";
    }
    else if(a==1||a==3||a==5||a==7||a==8||a==10||a==12&&b<32){
        cout<<"Yes";
    }
    else if(a==4||a==6||a==9||a==11&&b<31){
        cout<<"Yes";
    }
    else if(a>12) cout<<"No";
    else cout<<"No";
}
int main() {
    int a,b;
    cin>>a>>b;
    Print(a,b);
    return 0;
}