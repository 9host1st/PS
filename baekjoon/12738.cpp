#include <bits/stdc++.h>
using namespace std;
int dp[1000001], N, a[1000001];
int len;
void solve() {
    for(int i = 1; i <= N; i++) {
        int here;
        cin >> here;
        auto pos = lower_bound(a + 1, a + len + 1, here);
        *pos = here;
        if(pos == a + len + 1) len++;
    }
    cout << len;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    solve();
}