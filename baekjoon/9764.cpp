#include <bits/stdc++.h>

using namespace std;

int N, T;
int dp[2001][2001];
const int MOD = 100999;
void solve() {
	for(int i = 0; i <= 2000; i++) dp[0][i] = 1;
	for(int i = 1; i <= 2000; i++) {
		for(int j = 1; j <= 2000; j++) {
			dp[i][j] = dp[i][j - 1];
			if(i >= j) dp[i][j] = (dp[i][j] + dp[i - j][j - 1]) % MOD;
		}
	}
}

int main() {
	cin >> N;
	solve();
	while(N--) {
		cin >> T;
		cout << dp[T][T] << '\n';
	}
}
