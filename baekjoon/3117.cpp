#include <bits/stdc++.h>
using namespace std;
int N, K, M;
int spa[100001][31];
int a[100001];
void solve() {
    for(int i = 1; i <= N; i++) spa[i][0] = a[i];
    for(int j = 1; j < 30; j++) for(int i = 1; i <= N; i++) spa[i][j] = spa[spa[i][j - 1]][j - 1];
    while(M--) {
    
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> M;
    for(int i = 1; i <= N; i++) cin >> a[i];
    solve();
}