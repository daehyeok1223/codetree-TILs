#include <iostream>

using namespace std;

int n, m;
int graph[1001][1001];
bool visited[1001];
int ans;

void DFS(int cnt){
    for(int i = 1; i <= n; i++){
        if(graph[cnt][i] == 1 && !visited[i]){
            visited[i] = true;
            ans++;
            DFS(i);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
        
    }

    visited[1] = true;
    DFS(1);

    cout<<ans;

    return 0;
}
