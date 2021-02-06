#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;
pii a, b, c, d;
int ccw(pii v1, pii v2) {
	int t = v1.x * v2.y - v2.x * v1.y;
	return (t > 0) - (t < 0);
}
int ccw2(pii a, pii b, pii c) {
	return ccw({b.x - a.x, b.y - a.y}, {c.x - b.x, c.y - b.y});
	int t = a.x * b.y + b.x * c.y + c.x * a.y;
	t -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (t > 0) - (t < 0);
}

bool f() {
	int ab = ccw2(a, b, c) * ccw2(a, b, d);
	int cd = ccw2(c, d, a) * ccw2(c, d, b);
	if(ab == 0 && cd == 0) {
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	cout << (ccw2(a, b, c) * ccw2(a, b, d) < 0);
}
