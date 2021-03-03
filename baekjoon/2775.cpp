#include <bits/stdc++.h>
using namespace std;
int t, k, n;
int a0[15];
int b[15][15];
void init() { for(int i = 1; i <= 14; i++) for(int j = 1; j <= 14; j++) b[i][j] = 0; }
void solve() {
	for(int i = 1; i <= 14; i++) b[0][i] = i;
	while(t--) {
		init();
		cin >> k >> n;
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				for(int l = 1; l <= j; l++) b[i][j] += b[i - 1][l];
			}
		}
		cout << b[k][n] << '\n';
	}
}
int main() {
	cin >> t;
	solve();
}
