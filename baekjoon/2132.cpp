#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int n, a, b, d[10001], x, y;
vector<pii> adj[10001];
bool vis[10001];
int ans;
vector<pii> res;

void init() { for(int i = 0; i < n; i++) vis[i] = false; }

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

void dfs(int k, int ret) {
    vis[k] = true;
    ans = max(ans, ret);
    if(k == n) {
        ans = max(ans, ret);
        return;
    }
    for(int i = 0; i < adj[k].size(); i++) {
        if(adj[k][i].first && !vis[adj[k][i].first]) {
            dfs(adj[k][i].first, ret + adj[k][i].second);
        }
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {
        init();
        ans = 0;
        dfs(i, d[i]);
        res.push_back({ans, i});
    }
    sort(res.begin(), res.end(), compare);
    int x = res[0].first;
    int y = res[0].second;
    
    for(int i = 0; i < n; i++) {
        if(res[i].second != y) {
            if(res[i].first == x) {
                y = min(y, res[i].second);
            }
        }
    }
    cout << x << ' ' << y << '\n';
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back({b, d[b]});
    }
    solve();
}
