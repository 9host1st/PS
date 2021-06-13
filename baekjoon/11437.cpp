#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N, M, x, y;
vector<int> v[50001];
int h[50001], pa[50001];
void dfs(int k) {
    for(int t:v[k]) {
        if(pa[t] == 0) {
            pa[t] = k; h[t]=h[k]+1;
            dfs(t);
        }
    }
}
void solve() {
    pa[1] = 1;
    dfs(1);
    cin >> M;
    while(M--) {
        cin >> x >> y;
        while(h[x] < h[y]) y = pa[y];
        while(h[x] > h[y]) x = pa[x];
        while(x != y) x = pa[x], y = pa[y];
        cout << x << '\n';
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    N = N - 1;
    while(N--) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve();
}