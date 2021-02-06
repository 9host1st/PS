#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

double dist(pii x, pii y) {
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

pii move(pii x, pii y, pii z) {
	return {x.first + z.first - y.first, x.second + z.second - y.second};
}

double ans(pii x, pii y, pii z) {
	pii w = move(x, y, z);
	double t =  dist(y, z) + dist(z, w) + dist(w, x) + dist(x, y);
	return t;
}

int ccw(pii v1, pii v2) {
	int t = v1.first * v2.second - v2.first * v1.second;
	return (t > 0) - (t < 0);
}

int ccw2(pii a, pii b, pii c) {
	return ccw({b.first - a.first, b.second - a.second}, {c.first - b.first, c.second - b.second});
	int t = a.first * b.second + b.first * c.second + c.first * a.second;
	t -= a.second * b.first + b.second * c.first + c.second * a.first;
	return (t > 0) - (t < 0);
}

int main() {
	pii a, b, c;
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
	cout << max({ans(a, b, c), ans(a, c, b), ans(b, a, c), ans(b, c, a), ans(c, b, a), ans(c, a, b)}) - min({ans(a, b, c), ans(a, c, b), ans(b, a, c), ans(b, c, a), ans(c, b, a), ans(c, a, b)});
}
