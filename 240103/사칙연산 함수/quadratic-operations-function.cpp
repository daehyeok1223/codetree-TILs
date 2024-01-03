#include <iostream>
using namespace std;

void Add(int a,int b){
    cout<<a<<" + "<<b<<" = "<<a+b;
}
void Sub(int a,int b){
    cout<<a<<" - "<<b<<" = "<<a-b;
}
void Mul(int a,int b){
    cout<<a<<" * "<<b<<" = "<<a*b;
}
void Div(int a,int b){
    cout<<a<<" / "<<b<<" = "<<a/b;
}
int main() {
    int a,b;
    char c;
    cin >>a>>c>>b;
    if(c=='+'){
        Add(a,b);
    }
    else if(c=='-'){
        Sub(a,b);
    }
    else if(c=='*'){
        Mul(a,b);
    }
    else if(c=='/'){
        Div(a,b);
    }
    else cout<<"False";
    return 0;
}