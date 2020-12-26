#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, x, y, d;
vector<pii> adj[201];
const ll INF = 2e9;
int dist[201];
int main() {
    cin >> n >> m;
    while(m--) {
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
    }
    fill(dist, dist + n, INF);
    dist[0] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            for(auto &p : adj[j]) {
                int next = p.first;
                int d = p.second;
                if(dist[j] != INF && dist[next] > dist[j] + d) dist[next] = dist[j] + d;
            }
        }
    }
    for(int i = 1; i < n; i++) cout << dist[i] << '\n';
}
