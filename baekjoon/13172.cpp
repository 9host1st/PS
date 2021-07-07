#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll M, N[10001], S[10001];

ll gcd(ll x, ll y) {
	if(x == 0) return y;
	if(y == 0) return x;
	return gcd(y, x%y);
}

ll f(ll x, ll y) {
	if(y == 1) return x;
	if(y & 1) return x * f(x, y - 1) % MOD;
	ll res = f(x, y/2);
	 return (res*res) % MOD;
}

void solve() {
	ll ans = 0;
	for(int i = 1; i <= M; i++) {
		ll b = 0;
		ll g = gcd(S[i], N[i]);
		N[i] /= g;
		S[i] /= g;
		b = f(N[i], MOD - 2);
		ans = (ans + (S[i] * b)) % MOD;
	}
	cout << ans % MOD;
}

int main() {
	cin >> M;
	for(int i = 1; i <= M; i++) cin >> N[i] >> S[i];
	solve();
}
