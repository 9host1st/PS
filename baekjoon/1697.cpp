#include <bits/stdc++.h>
using namespace std;
int N, K;
int ans;
queue<pair<int, int> > q;
bool vis[400001];

int main() {
    cin >> N >> K;
    q.push({N, 0});
    vis[N] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int tmp = cur.first;
        int score = cur.second;
        if(tmp == K) {
            cout << score << '\n';
            break;
        } else {
            int newTmp = tmp - 1;
            if(tmp - 1 >= 0 && !vis[newTmp]) {
                q.push({newTmp, score + 1});
                vis[newTmp] = 1;
            }
            if(tmp + 1 <= 100000 && !vis[tmp + 1]) {
                q.push({tmp + 1, score + 1});
                vis[tmp + 1] = 1;
            }
            if(tmp * 2 <= 100000 && !vis[tmp * 2]) {
                q.push({tmp * 2, score + 1});
                vis[tmp * 2] = 1;
            }
        }
    }
}
