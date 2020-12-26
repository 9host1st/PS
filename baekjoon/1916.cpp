#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m, s, e;
priority_queue<pii> pq;
vector<pii> adj[1001];
const ll INF = 2e9;
ll dist[100001];
int main() {
    cin >> n >> m;
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    cin >> s >> e;
    for(int i = 0; i <= 100000; i++) dist[i] = INF;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        auto tmp = pq.top();
        int curr = -tmp.first;
        int curr2 = tmp.second;
        pq.pop();
        if(dist[curr2] < curr) continue;
        for(int i = 0; i < adj[curr2].size(); i++) {
            int next = adj[curr2][i].first;
            int nextDist = curr + adj[curr2][i].second;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    cout << dist[e] << '\n';
}
