#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 15746;
ll N, dp[1000001];

void solve() {
    dp[1] = 1;
    dp[2] = 2; 
    for(int i = 3; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    cout << dp[N];
}

int main() {
    cin >> N;
    solve();
}

