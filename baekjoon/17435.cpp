#include <bits/stdc++.h>
using namespace std;
int m, Q, f[200001], spa[500001][21];
void solve() {
    cin >> Q;
    for(int i = 1; i <= m; i++) spa[i][0] = f[i];
    for(int j = 1; j < 20; j++) for(int i = 1; i <= m; i++) spa[i][j] = spa[spa[i][j - 1]][j - 1];
    while(Q--) {
        int n, x;
        cin >> n >> x;
        for(int i = 19; i >= 0; i--) 
            if(n & (1 << i)) 
                x = spa[x][i];
        cout << x << '\n';
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> f[i];
    solve();
}