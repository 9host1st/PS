#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[91];
int N;
void solve() {
    dp[1] = 1; dp[2] = 1; dp[3] = 2;
    for(int i = 4; i <= 90; i++) dp[i] = (dp[i - 1] + dp[i - 2]);
    cout << dp[N];
}
int main() {
    cin >> N;
    solve();
}