#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000000;
int N;
ll dp[101][11];
ll ans;
void solve() {
    for(int i = 1; i <= 9; i++) dp[1][i] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) dp[i][j] = dp[i - 1][j + 1] % MOD;
            if(j == 9) dp[i][j] = dp[i - 1][j - 1] % MOD;
            else dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
        }
    }
    for(int i = 0; i <= 9; i++) ans = (ans + dp[N][i]) % MOD;
    cout << ans % MOD;
}
int main() {
    cin >> N;
    solve();
}