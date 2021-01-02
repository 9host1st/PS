#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
ll p = 1e9 + 7;
ll N, K;
ll gcd(ll x, ll y) { return x?gcd(y%x, x):y; };
pll ssolve(ll a, ll b) {
    if(a == 0) return {0, 1};
    if(b == 0) return {1, 0};
    auto tmp = ssolve(b % a, a);
    return {tmp.second - tmp.first * (b/a), tmp.first};
}
pll solve(ll a, ll b) {
    ll g = gcd(a, b);
    return ssolve(a/g, b/g);
}
ll fac(ll a, ll b) {
    ll tmp = 1;
    for(ll i = 1; i <= (b - a); i++) {
        tmp *= i;
        tmp %= p;
    }
    return tmp % p;
}
int main() {
    cin >> N >> K;
    auto x = solve((fac(K, N) * fac(0, K)) % p, p);
    ll ans = (fac(0, N) * (x.first % p)) % p;
    if(ans < 0) cout << (ans + p) % p << '\n';
    else cout << ans << '\n';
}
