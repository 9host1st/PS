#include <bits/stdc++.h>
using namespace std;
int a[100001], dp[1000001], n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
		ans = max(ans, dp[a[i]]);
	}
	cout << ans << '\n';
}
