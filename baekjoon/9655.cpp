#include <bits/stdc++.h>
using namespace std;
int dp[1001], N;
void solve() {
	dp[1] = 1; 
	dp[2] = 0;
	dp[3] = 1;
	for(int i = 4; i <= N; i++) {
		if(dp[i - 1] || dp[i - 3]) dp[i] = 0;
		else if(!dp[i - 1] && !dp[i - 3]) dp[i] = 1;
	}
	if(dp[N]) cout << "SK";
	else if(!dp[N]) cout << "CY";
}
int main() {
	cin >> N;
	solve();	
}
