#include <bits/stdc++.h>
using namespace std;
int n, k, a[101], dp[10001];
void solve() {
	fill(dp, dp + 10001, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = a[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	if(dp[k] == 1e9) cout << "-1" << '\n';
	else cout << dp[k] << '\n';
}
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	solve();
}
