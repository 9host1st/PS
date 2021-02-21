#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int x, y, N, M;
int degree[1001];
int ans[1001];
queue<int> q;
int main() {
    cin >> N >> M;
    for(int i = 0; i < 1001; i++) ans[i] = 1;
    while(M--) {
        cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
    for(int i = 1; i <= N; i++) {
        if(degree[i] == 0) q.push(i);
    }
    for(int i = 1; i <= N; i++) {
        int n = q.front();
        q.pop();
        for(int i = 0; i < adj[n].size(); i++) {
            int nxt = adj[n][i];
            degree[nxt]--;
            ans[nxt] = ans[n] + 1;
            if(degree[nxt] == 0) q.push(nxt);
        }
    }
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
}
