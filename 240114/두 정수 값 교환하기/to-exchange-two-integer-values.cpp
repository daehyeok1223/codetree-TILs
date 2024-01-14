#include <iostream>
using namespace std;

void swap(int a,int b){
    int temp = a;
    a=b;
    b=temp;
    cout<<a<<" "<<b;
}

int main() {
    int a,b;
    cin>>a>>b;
    swap(a,b);
    
    return 0;
}