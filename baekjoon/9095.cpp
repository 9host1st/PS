#include <bits/stdc++.h>
using namespace std;
int T, n, dp[11];
void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 10; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}
int main() {
    cin >> T;
    solve();
    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}