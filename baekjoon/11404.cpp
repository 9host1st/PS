#include <bits/stdc++.h>
using namespace std;
int n, m;
int adj[101][101];
const int INF = 1e8;

void init() {
    for(int i = 0; i < 101; i++){
        for(int j = 0; j <101; j++){
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    init();
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x][y] = min(adj[x][y], z);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(adj[j][k] > adj[j][i] + adj[i][k]) adj[j][k] = adj[j][i] + adj[i][k];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] >= INF) cout << 0 << ' ';
            else cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}
