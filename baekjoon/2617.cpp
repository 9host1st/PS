#include <bits/stdc++.h>
using namespace std;

int N, M, x, y;
int a[100][5000];
int b[100][5000];
bool v1[100], v2[100];
int cnt1, cnt2;
int ans;
void init() { 
    for(int i = 1; i <= N; i++) { 
        v1[i] = false; 
        v2[i] = false; 
    } 
}

void dfs1(int k) {
    v1[k] = true;
    cnt1++;
    for(int i = 1; i <= N; i++)
        if(!v1[i] && a[k][i])
            dfs1(i);
}

void dfs2(int k) {
    v2[k] = true;
    cnt2++;
    for(int i = 1; i <= N; i++)
        if(!v2[i] && b[k][i])
            dfs2(i);
}

void solve() {
    for(int i = 1; i <= N; i++) {
        init();
        cnt1 = 0; cnt2 = 0;
        dfs1(i); dfs2(i);
        cnt1--; cnt2--;
        if((N - 1) / 2 < cnt1 || (N - 1) / 2 < cnt2) ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin >> N >> M;
    while(M--) {
        cin >> x >> y;
        a[y][x] = 1;
        b[x][y] = 1;
    }
    solve();
}
