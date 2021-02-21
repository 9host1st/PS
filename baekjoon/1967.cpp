#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<pii> a[10001];
int dist[10001];
bool vis[10001];
int x, y, d, n;

int dfs(int k) {
}

int main() {
    cin >> n;
    while(n--) {
        cin >> x >> y >> d;
        a[x].push_back({y, d});
        a[y].push_back({x, d});
    }
}
