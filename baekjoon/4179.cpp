#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int R, C;
string a[1002];
queue<pii> Q1;
queue<pii> Q2;
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inrange(int nx, int ny) {
    if(nx < 0 || nx >= R || ny < 0 || ny >= C) return false;
    return true;
}

void init1() {
    for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) dist1[i][j] = -1;
}
void init2() {
    for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) dist2[i][j] = -1;
}

int main() {
    cin >> R >> C;
    init1();
    init2();
    for(int i = 0; i < R; i++) cin >> a[i];
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(a[i][j] == 'J') {
                Q1.push({i, j});
                dist1[i][j] = 0;

            } if(a[i][j] == 'F') {
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
            if(a[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            dist2[nx][ny] = dist2[x][y] + 1;
            Q2.push({nx, ny});
        }
    }
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << dist2[i][j] << ' ';
        }
        cout << '\n';
    }

    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!inrange(nx, ny)) {
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++) {
                        cout << dist1[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << dist1[x][y] + 1 << '\n';
                return 0;
            }
            if(dist1[nx][ny] >= 0 || a[nx][ny] == '#') continue;
            if(dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[x][y] + 1) continue;
            dist1[nx][ny] = dist1[x][y] + 1;
            Q1.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
