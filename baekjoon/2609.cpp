#include <bits/stdc++.h>
using namespace std;
int x, y;
int gcd(int m, int n) {
	if(n == 0) return m;
	if(m == 0) return n;
	return gcd(n, m % n);
}
int lcm(int m, int n) {
	return m/gcd(m,n) * n;
}
void solve() {
	cout << gcd(x, y) << '\n';
	cout << lcm(x, y) << '\n';
}
int main() {
	cin >> x >> y;
	solve();
}
