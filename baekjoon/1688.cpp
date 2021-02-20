#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
using ll=long long;
int N, x, y;
pii a[10001];
int ccw(pii v1, pii v2) {
	ll t = (ll)v1.first * (ll)v2.second - (ll)v2.first * (ll)v1.second;
	return (t > 0) - (t < 0);
}

int ccw2(pii a, pii b, pii c) {
	return ccw({b.first - a.first, b.second - a.second}, {c.first - b.first, c.second - b.second});
	ll t = (ll)a.first * b.second + (ll)b.first * c.second + (ll)c.first * a.second;
	t-= (ll)a.second*b.first + (ll)b.second*c.first + (ll)c.second*a.first;
	return (t>0)-(t<0);
}
bool itc(pii a, pii b, pii c, pii d) {
	int ab = ccw2(a, b, c) * ccw2(a, b, d);
	int cd = ccw2(c, d, a) * ccw2(c, d, b);
	if(ab == 0 && cd == 0) {
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);
		if(a <= d && c <= b) return true;
		return false;
	}
	return (ab <= 0) && (cd <= 0);
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
	a[N] = a[0];
	pii mp = {1000000009, 13};
	for(int i = 0; i < 3; i++) {
		pii A;
		cin >> A.first >> A.second;
		int cnt = 0;
		for(int j = 0; j < N; j++) {
			if(itc(A, mp, a[j], a[j + 1])) cnt ++;
			if(itc(A, A, a[j], a[j + 1])) { cnt = 1; break; }
		}
		cout << cnt % 2 << '\n';
	}
}
