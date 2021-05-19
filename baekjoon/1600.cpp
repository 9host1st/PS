#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int K, W, H, a[201][201];
bool vis[201][201][31];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx2[] = {-2, -1, 1, 2, 2, 1, -1, 2};
const int dy2[] = {1, 2, 2, 1, -1, -2, -2, -1};

int horseCnt;
int ret;

struct state {
    int x;
    int y;
    int cnt;
    int ability;
};

queue<state> q;

bool inrange(int nx, int ny) {
    if(nx < 0 || nx >= W || ny < 0 || ny >= H) return false;
    return true;
}

int solve() {
    q.push({0, 0, 0, 0});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        ret++;
        int x = cur.x;
        int y = cur.y;
        int cnt = cur.cnt;
        int ability = cur.ability;

        if((x == W - 1) && (y == H - 1)) return cnt;
        if(ability < K) {
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.x + dx2[dir];
                int ny = cur.y + dy2[dir];
                if(inrange(nx, ny) && !vis[nx][ny][ability + 1] && a[nx][ny] == 0) {
                    vis[nx][ny][ability + 1] = true;
                    cur.x = nx, cur.y = ny, cur.cnt = cnt+1, cur.ability = ability+1;
                    q.push({cur.x, cur.y, cur.cnt, cur.ability});
                }
            }
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(inrange(nx, ny) && !vis[nx][ny][ability] && a[nx][ny] == 0) {
                vis[nx][ny][ability] = true;
                cur.x = nx, cur.y = ny, cur.cnt = cnt + 1, cur.ability = ability;
                q.push({cur.x, cur.y, cur.cnt, cur.ability});
            }
        }
    }
    return -1;
}

int main() {
    cin >> K;
    cin >> W >> H;
    for(int i = 0; i < W; i++) for(int j = 0; j < H; j++) cin >> a[i][j];
    cout << solve() << '\n';
}
