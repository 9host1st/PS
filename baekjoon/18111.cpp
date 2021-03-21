#include <bits/stdc++.h>
using namespace std;
int N, M , B, a[501][501], b[501][501];
int minH = 987654321;
int maxH, resH;
int f(int h) {
	int t = 0;
	int inven = B;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(a[i][j] > h) {
				inven += (a[i][j] - h);
				t += (a[i][j] - h) * 2;
			} else if(a[i][j] < h) {
				inven -= (h - a[i][j]);
				t += (h - a[i][j]);
			}
		}
	}
	if(inven < 0) return -1;
	return t;
}
void solve() {
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> a[i][j];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			minH = min(minH, a[i][j]);		
			maxH = max(maxH, a[i][j]);
		}
	}
	int res = 987654321;
	for(int i = minH; i <= maxH; i++) {
		int cur = f(i);
		if(cur == -1) continue;;
		if(res >= cur) {
			res = cur;
			resH = i;	
		}
	}
	cout << res << ' ' << resH << '\n';
}
int main() {
	cin >> N >> M >> B;
	solve();
}
