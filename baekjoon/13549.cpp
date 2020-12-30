#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int N, K;
queue<pii> q;
bool vis[200001];

int main() {
    cin >> N >> K;
    q.push({N, 0});
    vis[N] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int ret = cur.second;
        if(x == K) {
            cout << ret << '\n';
            return 0;
        }
        if(2 * x <= 200000 && !vis[2*x]) {
            q.push({2*x, ret});
            vis[2*x] = true;
        }
        if(x - 1 >= 0 && !vis[x - 1]) {
            q.push({x - 1, ret + 1});
            vis[x - 1] = true;
        }
        if(x + 1 <= 100000 && !vis[x + 1]) {
            q.push({x + 1, ret + 1});
            vis[x + 1] = true;
        }
    }
}
