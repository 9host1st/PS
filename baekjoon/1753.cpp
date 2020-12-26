#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int v, e, k;
ll dist[20001];
const ll INF = 987654321;
bool check[20001];
vector<pii> adj[20001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    cin >> k;
    for(int i = 1; i <= v; i++) dist[i] = INF;
    dist[k] = 0;
    while(e--) {
        int p, q, d;
        cin >> p >> q >> d;
        adj[p].push_back({q, d});
    }
    pq.push({0, k});
    while(!pq.empty()) {
        auto cur = pq.top();
        int x = cur.second; 
        int y = cur.first;
        pq.pop();
        if(check[x]) continue;
        check[x] = true;
        for(auto i : adj[x]) {
            int z = i.first; 
            int zz = i.second;
            if(dist[z] > dist[x] + zz) {
                dist[z] = dist[x] + zz;
                pq.push({dist[z], z});
            }
        }
    }
    for(int i = 1; i <= v; i++) {
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}
