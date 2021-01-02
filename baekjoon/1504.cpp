#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
const ll INF = 1e9;
int N, E;
int v1, v2;
ll x, y, d;
ll dist[801];
vector<pll> adj[801];
void init() { for(int i = 0; i < 801; i++) dist[i] = INF; }
ll f(int v1, int v2) {
    init();
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[v1] = 0;
    pq.push({dist[v1], v1});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        ll cost = cur.first;
        ll vertex = cur.second;
        for(int i = 0; i < adj[vertex].size(); i++) {
            ll nxt = adj[vertex][i].first;
            ll ncost = adj[vertex][i].second;

            if(dist[nxt] > cost + ncost) {
                dist[nxt] = cost + ncost;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    return dist[v2];
}

void solve() {
    ll a = f(1, v1);
    ll b = f(v1, v2);
    ll c = f(v2, N);
    ll e = f(1, v2);
    ll p = f(v2, v1);
    ll q = f(v1, N);
    ll ans = min(a+b+c, e+p+q);
    if(ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main() {
    cin >> N >> E;
    while(E--) {
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }
    cin >> v1 >> v2;
    solve();
}
