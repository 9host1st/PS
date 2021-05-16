#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N, a[101][101], x, y, ans;
bool inrange(int nx, int ny) {
	if(nx < 1 || nx >= 100 | ny < 1 || ny >= 100) return false;
	return true;
}

int chk(int x, int y) {
	int t = 0;
	for(int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(inrange(nx, ny)) 
			if(a[nx][ny] == 0)
				t++;
	}

	return t;
}
void solve() {	
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			if(a[i][j] == 1) {
				if(chk(i, j) >= 1) {
					for(int dir = 0; dir < 4; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if(a[nx][ny] == 0) a[nx][ny] = 2;
					}
				}
			}
		}
	}
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			if(a[i][j] == 2) ans++;
		}
	}
	cout << ans << '\n';
}
int main() {
	cin >> N;
	while(N--) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	solve();
}
