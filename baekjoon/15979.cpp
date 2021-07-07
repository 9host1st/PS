#include <bits/stdc++.h>
using namespace std;
int x, y;
int gcd(int x, int y) {
	if(x == 0)return y;
	if(y == 0) return x;
	return gcd(y, x%y);
}
void solve() {
	x = abs(x); y = abs(y);
	if(x == 0 && y == 0) cout << 0 << '\n';
	else if(gcd(x, y) == 1) cout << 1 << '\n';
	else cout << 2 << '\n';
}
int main() {
	cin >> x >> y;
	solve();
}
