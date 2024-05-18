#include <iostream>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int N;
    char a;
    cin>>N;
    int x = 0;
    int y = 0;
    for(int i = 0; i<N; i++){
        int b;
        cin>>a;
        if(a=='N'){
            cin>>b;
            for(int i=0;i<b; i++){
                x = x + dx[1];
                y = y + dy[1];
            }
        }
        else if(a=='E'){
            cin>>b;
            for(int i=0;i<b; i++){
                x = x + dx[0];
                y = y + dy[0];
            }
        }
        else if(a=='S'){
            cin>>b;
            for(int i=0;i<b; i++){
                x = x + dx[3];
                y = y + dy[3];
            }
        }
        else if(a=='W'){
            cin>>b;
            for(int i=0;i<b; i++){
                x = x + dx[2];
                y = y + dy[2];
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}