#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N, M, x, y;
vector<int> v[100001];
int dep[100001];
int spa[100001][31];
bool vis[100001];
void dfs(int x) {
    for(auto i:v[x]) {
        if(!spa[i][0]) {
            spa[i][0] = x;
            dep[i] = dep[x] + 1;
            dfs(i);
        }
    }
}

void solve() {
    cin >> M;
    spa[1][0] = 1;
    dfs(1);
    for(int j = 1; j <= 17; j++) for(int i = 1; i <= N; i++) spa[i][j] = spa[spa[i][j - 1]][j - 1];
    while(M--) {
        cin >> x >> y;
        if(dep[x] < dep[y]) x ^= y ^= x ^= y;
        for(int i = 17; i >= 0; i--) if(dep[spa[x][i]]>=dep[y]) x=spa[x][i];
        if(x == y) cout << x << '\n';
        else {
            for(int i = 17; i >= 0; i--) {
                if(spa[x][i] != spa[y][i]) x = spa[x][i], y = spa[y][i];
            }
            cout << spa[x][0] << '\n';
        }
    }
}
int main() {
    cin >> N;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve();
}