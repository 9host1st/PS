#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int n, a[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[101][101];
bool vis2[101][101];
bool vis3[101][101];
int cnt = 1;
queue<pii> edgePair;
bool inrange(int nx, int ny) {
    if(nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
    return true;
}

void fill1() {
    queue<pii> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] >= 1 && !vis[i][j]) {
                q.push({i, j});
                a[i][j] = cnt;
                vis[i][j] = true;
                while(!q.empty()) {
                    auto cur = q.front(); q.pop();
                    int x = cur.first;
                    int y = cur.second;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(!inrange(nx, ny)) continue;
                        if(vis[nx][ny] || a[nx][ny] == 0) continue;
                        vis[nx][ny] = true;
                        a[nx][ny] = cnt;
                        q.push({nx, ny});
                    }
                }
                cnt++;
            }
        }
    }
}

void init() { for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) vis2[i][j] = false; }

int f(int p) {
    int ret = 0;
    init();
    queue<pii> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == p) {
                vis2[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        int curSize = q.size();
        for(int i = 0; i < curSize; i++) {
            auto cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(!inrange(nx, ny)) continue;
                if(a[nx][ny] != p && a[nx][ny]) return ret;
                if(vis2[nx][ny] || a[nx][ny] != 0) continue;
                vis2[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        ret ++;
    }
}
void solve() {
    int ans = 0x41414141;
    fill1();
    int dist = 0;
    for(int i = 1; i < cnt; i++) {
        dist = f(i);
        ans = min(ans, dist);
    }
    cout << ans<< '\n';
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
    solve();
}
