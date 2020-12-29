#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int t, R, C;
string a[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    for(int i = 0; i < C; i++) for(int j = 0; j < R; j++) dist1[i][j] = -1;
    for(int i = 0; i < C; i++) for(int j = 0; j < R; j++) dist2[i][j] = -1;
}

bool inrange(int nx, int ny) {
    if(nx < 0 || nx >= C || ny < 0 || ny >= R) return false;
    return true;
}

void printBoard() {
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < R; j++) {
            cout << dist2[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    queue<pii> Q1;
    queue<pii> Q2;
    cin >> R >> C;
    init();
    for(int i = 0; i < C; i++) cin >> a[i];
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < R; j++) {
            if(a[i][j] == '@') {
                Q1.push({i, j});
                dist1[i][j] = 0;
            } if(a[i][j] == '*') {
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }
    while(!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!inrange(nx, ny)) continue;
            if(dist2[nx][ny] >= 0 || a[nx][ny] == '#') continue;
            dist2[nx][ny] = dist2[x][y] + 1;
            Q2.push({nx, ny});
        }
    }
    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!inrange(nx, ny)) {
                cout << dist1[x][y] + 1 << '\n';
                return;
            } if(dist1[nx][ny] >= 0 || a[nx][ny] == '#') continue;
            if(dist2[nx][ny] <= dist1[x][y] + 1 && dist2[nx][ny] != -1) continue;
            dist1[nx][ny] = dist1[x][y] + 1;
            Q1.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main () {
    cin >> t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(t--) solve();
}
