#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll T, x, a[1000001], dp[1000001];
const ll MOD = 1e9 + 9;
void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 1000000; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
}
int main() {
    cin >> T;
    solve();
    while(T--) {
        cin >> x;
        cout << dp[x] << '\n';
    }
}