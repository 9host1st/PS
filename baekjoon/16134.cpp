#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll N, R;

ll mul(ll x, ll y, ll p) {
    ll ans = 1;
    while(y > 0) {
        if(y % 2 != 0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y /= 2;
    }
    return ans;
}

int main() {
    cin >> N >> R;
    ll ans = 1;
    ll t1 = 1;
    ll t2 = 1;
    for(ll i = 1; i <= N; i++) {
        t1 *= i;
        t1 %= MOD;
    }
    for(ll i = 1; i <= R; i++) {
        t2 *= i;
        t2 %= MOD;
    }
    for(ll i = 1; i <= N - R; i++) {
        t2 *= i;
        t2 %= MOD;
    }
    ll t3 = mul(t2, MOD - 2, MOD);
    t3 %= MOD;
    ans = t1 * t3;
    ans %= MOD;
    cout << ans;
}