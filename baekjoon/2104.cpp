#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll a[100001];
ll sum, h;
ll solve(int l, int r) {
    if(l == r) return a[l] * a[r];
    int mid = (l + r) / 2;
    ll ret = max(solve(l, mid), solve(mid + 1, r));
    ll s = mid, e = mid + 1;
    h = min(a[s], a[e]);
    sum = (a[s] + a[e]);
    ret = max(ret, h * sum);
    while(l < s || e < r) {
            if(e < r && (s == l || a[s - 1] < a[e + 1])) {
                sum += a[e + 1];
                ++e;
                h = min(h, a[e]);
            } else {
                sum += a[s - 1];
                --s;
                h = min(h, a[s]);
            }
            ret = max(ret, sum * h);
    }
    return ret;
}
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    cout << solve(1, N);
}
