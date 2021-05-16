#include <bits/stdc++.h>
using namespace std;
int N, dp[1000001];
void solve() { 
	dp[1] = 0;
	for(int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
		if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
	}
	cout << dp[N];
}
int main() {
	cin >> N;
	solve();
}
