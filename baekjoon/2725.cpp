#include <bits/stdc++.h>
using namespace std;
int C, N;
int dp[1001];
int gcd(int x, int y) {
	if(y == 0) return x;
	if(x == 0) return y;
	return gcd(y, x%y);
}
void f() {
	for(int i = 0; i <= 1000; i++, dp[i] = dp[i - 1])
		for(int j = 0; j < i; j++) 
			if(gcd(i,j) == 1) dp[i] += 2;
}


int main() {
	cin >> C;
	f();
	while(C--) {
		cin >> N;
		cout << dp[N] + 1<<'\n';
	}
}
