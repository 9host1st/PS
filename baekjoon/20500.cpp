#include <bits/stdc++.h>
using namespace std;
int a[1516];
const int MOD = 1e9 + 7;
int N;
void solve() {
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	for(int i = 4; i <= 1515; i++) a[i] = ((a[i - 1] % MOD) +( a[i - 2] * 2) % MOD) % MOD;
	cout << a[N] << '\n';
}
int main() {
	cin >> N;
	solve();
}
