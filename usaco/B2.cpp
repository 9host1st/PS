#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, ans;
pii a[100001];
int b[1001][1001];
bool inrange(int nx, int ny) {
	if(nx < 0 || nx > 1000 || ny < 0 || ny > 1000) return false;
	return true;
}
void solve() {
	for(int i = 0; i < N; i++) {
		int ret = 0;
		for(int dir = 0; dir < 4; dir++) {
			int nx = a[i].first + dx[dir];
			int ny = a[i].second + dy[dir];
			if(!inrange(nx, ny)) continue;
			if(b[nx][ny]) ret++;
		}
		if(ret == 3) ans++;
	}
	cout << ans << '\n';
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a[i].first >> a[i].second;
		b[a[i].first][a[i].second] = 1;		
	}
	solve();
}
