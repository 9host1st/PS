#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[1001][1001], N, K;
const ll MOD = 10007;
void solve() { 
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= min(i, K); j++) {
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[N][K];
}
int main() {
    cin >> N >> K;
    solve();
}