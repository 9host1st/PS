#include <bits/stdc++.h>
using namespace std;
int N, a[1001][1001], dp[1001][1001];
void solve() {
	for(int i = 1; i <= 3; i++) dp[1][i] = a[1][i];
	for(int i = 2; i <= N; i++) {
		for(int j = 1; j <= 3; j++) {
			if(j == 1) dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + a[i][j];
			if(j == 2) dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + a[i][j];
			if(j == 3) dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j - 2]) + a[i][j];
		}
	}
	cout << min({dp[N][1], dp[N][2], dp[N][3]});
}

int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= 3; j++) cin >> a[i][j];
	solve();
}
