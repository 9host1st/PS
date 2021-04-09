#include <bits/stdc++.h>
using namespace std;
int dp[1001], N;

void solve() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	for(int i = 4; i <= N; i++) {
		if(dp[i - 1] || dp[i - 3]) dp[i] = 0;
		else if(!dp[i - 1] && !dp[i - 3]) dp[i] = 1;
	}
	if(dp[N] == 1) cout << "SK" << '\n';
	else cout << "CY" << '\n';
}
int main() {
	cin >> N;
	solve();
}
