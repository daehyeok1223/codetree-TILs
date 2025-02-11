#include <iostream>
#include <string>

using namespace std;

string A;
int arr[30];

void Decide(){
    for(int i = 1; i < A.size(); i++){
        if(A[0] != A[i]){
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
    return;
}

int main() {
    cin >> A;

    Decide();

    return 0;
}