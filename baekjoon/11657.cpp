#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll edge[6001][3];
ll dist[501];
const ll INF = 1e8;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    bool mc = false;
    for(int i = 0; i < n; i++) {
        bool ischanged = false;
        for(int j = 0; j < m; j++) {
            int x = edge[j][0], y = edge[j][1], cost = edge[j][2];
            if(dist[x] != INF && dist[x] + cost < dist[y]) { dist[y] = dist[x] + cost; ischanged = true; }
        }
        if(!ischanged) break;
        if(i == n - 1 && ischanged == true) mc = true;
    }
    if(mc) cout << -1 << '\n';
    else {
        for(int i = 2; i <= n; i++) {
            if(dist[i] == INF) dist[i] = -1;
            cout << dist[i] << '\n';
        }
    }
}
