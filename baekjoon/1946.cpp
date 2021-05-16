#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int T, N, x, y, ans;
int minN = 987654321;
void solve() {
	ans = 0;
	minN = 987654321;
	cin >> N;
	vector<pii> v;
	for(int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < N; i++) {
		if(minN > v[i].second) {
			minN = v[i].second;
			ans++;
		}
	}
	cout << ans << '\n';
}
int main() {
	cin >> T;
	while(T--) solve();
}
