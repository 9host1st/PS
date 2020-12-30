#include <bits/stdc++.h>
using namespace std;
int L, R, C;

int dh[6]={0,0,0,0,1,-1};
int dy[6]={0,0,1,-1,0,0};
int dx[6]={1,-1,0,0,0,0};

string a[31][31];
int dist[31][31][31];

typedef struct {
    int x;
    int y;
    int z;
} st;

void init() { for(int i = 0; i < L; i++) for(int j = 0; j < R; j++) for(int k = 0; k < C; k++) dist[i][j][k] = -1; }

bool inrange(int nx, int ny, int nz) {
    if(nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) return false;
    return true;
}

void solve() {
    init();
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if(a[i][j][k] == 'S') {
                    queue<st> q;
                    q.push({i, j, k});
                    dist[i][j][k] = 0;
                    while(!q.empty()) {
                        auto cur = q.front(); q.pop();
                        int x = cur.x;
                        int y = cur.y;
                        int z = cur.z;
                        if(a[x][y][z] == 'E') {
                            cout << "Escaped in " << dist[x][y][z] << " minute(s)." << '\n';
                            return;
                        }
                        for(int dir = 0; dir < 6; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            int nz = z + dh[dir];
                            if(!inrange(nx, ny, nz)) continue;
                            if(dist[nx][ny][nz] >= 0 || a[nx][ny][nz] == '#') continue;
                            dist[nx][ny][nz] = dist[x][y][z] + 1;
                            q.push({nx, ny, nz});
                        }
                    }
                }
            }
        }
    }
    cout << "Trapped!" << '\n';
}

int main() {
    while(1) {
        cin >> L >> R >> C;
        if((L == 0) && (R == 0) && (C == 0)) return 0;
        for(int i = 0; i < L; i++) for(int j = 0; j < R; j++) cin >> a[i][j];
        solve();
    }
}
