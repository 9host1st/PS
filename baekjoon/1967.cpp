#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<pii> a[10001];
int dist[10001];
bool vis[10001];
int x, y, d, n;
int ans;
void init() { for(int i = 1; i <= n; i++) vis[i] = false; }
void dfs(int k, int ret) {
    vis[k] = true;
    ans = max(ans, ret);
    if(k == n) {
        ans = max(ans, ret);
        return;
    }
    for(int i = 0; i < a[k].size(); i++) {
        if(a[k][i].first && !vis[a[k][i].first]) {
            dfs(a[k][i].first, ret + a[k][i].second);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> x >> y >> d;
        a[x].push_back({y, d});
        a[y].push_back({x, d});
    }
    for(int i = 1; i <= n; i++) {
        init();
        dfs(i, 0);
    }
    cout << ans << '\n';
}
