#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int N, M, x, y, v[101];
int t = -1;
vector<pii> a, b;
int ans = -1;
int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> x >> y;
		a.push_back({x, y});
	} for(int i = 0; i < M; i++) {
		cin >> x >> y;
		b.push_back({x, y});
	}
	for(int i = 0; i < N; i++) {
		for(int j = t + 1; j <= t + a[i].first; j++) v[j] = a[i].second;
		t += a[i].first;
	}
	t = -1;
	for(int i = 0; i < M; i++) {
		for(int j = t + 1; j <= t + b[i].first; j++) 
			if(v[j] < b[i].second) ans = max(b[i].second - v[j], ans);
		t += b[i].first;
	}
	if(ans == -1) cout << 0 << '\n';
	else cout << ans << '\n';
}
