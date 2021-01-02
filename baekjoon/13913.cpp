#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N, K;
bool vis[200001];
int par[200001];
int ret;
queue<pii> q;
vector<int> ans;
int main() {
    cin >> N >> K;
    q.push({N, 0});
    vis[N] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        if(x == K) {
            ret = y;
            while(x != N) {
                ans.push_back(x);
                x = par[x];
            }
            break;
        }
        if(x - 1 >= 0 && !vis[x - 1]) {
            vis[x - 1] = true;
            par[x - 1] = x;
            q.push({x - 1, y + 1});
        }
        if(x + 1 <= 100000 && !vis[x + 1]) {
            vis[x + 1] = true;
            par[x + 1] = x;
            q.push({x + 1, y + 1});
        }
        if(x * 2 <= 200000 && !vis[2 * x]) {
            vis[x * 2] = true;
            par[x * 2] = x;
            q.push({x * 2, y + 1});
        }
    }
    cout << ret << '\n';
    cout << N << ' ';
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
