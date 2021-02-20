#include <bits/stdc++.h>
using namespace std;
using pii=pair<double, double>;
int N;
pii p[10001];
double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;
	double res = 0;
	for(int i = 1; i < N; i++) res += ccw(p[0].first, p[i - 1].first, p[i].first, p[0].second, p[i - 1].second, p[i].second);
	printf("%.1lf", abs(res));
}
