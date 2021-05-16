#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 10007;
ll dp[1001];
int n;
void solve() {
    dp[1] = 1; dp[2] = 3;
    for(int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
    cout << dp[n];
}
int main() {
    cin >> n;
    solve();
}