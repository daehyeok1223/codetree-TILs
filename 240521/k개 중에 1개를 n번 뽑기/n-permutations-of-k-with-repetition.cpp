#include <iostream>
#include<vector>

using namespace std;

int K,N;
vector<int> v;

void Print(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << '\n';
}

void choose(int depth){
    if(depth == N + 1){
        Print();
        return;
    }
    else{
        for(int i = 1; i <= K; i++){
            v.push_back(i);
            choose(depth + 1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> K >> N;
    choose(1);  

    return 0;
}