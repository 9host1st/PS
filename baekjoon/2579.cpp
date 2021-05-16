#include <bits/stdc++.h>
using namespace std;
int T, a[301], dp[301][2];
void solve() {
    if(T == 1) {
        cout << a[1] << '\n';
        return;
    }
    dp[1][1] = a[1]; dp[2][2] = a[1] + a[2];
    dp[1][2] = 0; dp[2][1] = a[2];
    for(int i = 3; i <= T; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + a[i];
        dp[i][2] = dp[i - 1][1] + a[i];
    }
    cout << max(dp[T][1], dp[T][2]);
}
int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) cin >> a[i];
    solve();
