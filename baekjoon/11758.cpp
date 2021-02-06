#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
pii a, b, c;
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
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
	cout << ccw2(a, b, c);
}
