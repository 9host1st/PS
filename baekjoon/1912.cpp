#include <bits/stdc++.h>
using namespace std;
int n, a[100001], dp[100001];
void solve() {
    dp[1] = a[1];
    for(int i = 2; i <= n; i++) dp[i] = max(dp[i - 1], 0) + a[i];
    cout << *max_element(dp + 1, dp + n + 1);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    solve();
}