#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int N, M;
int dp[10001];
void solve() {
	dp[0] = 1;
	for(int i = 1; i <= N; i++) 
		dp[i] = (dp[i - 1] % MOD + ((i >= M? dp[i - M]: 0)) % MOD) % MOD;
	cout << dp[N] % MOD;
}
int main() {
	cin >> N >> M;
	solve();	
}
