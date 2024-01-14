#include <iostream>
using namespace std;

bool Palin(string &s){
    int start=0;
    int end=s.length()-1;

    while(start<end)
    {
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    string input;
    cin>>input;
    if(Palin(input)){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}