/* 14430 */
#include <bits/stdc++.h>
using namespace std;
int N, M, a[301][301], cache[301][301];
int f(int x, int y) {
	if(x < 1 || y < 1) return 0;
	int& ret = cache[x][y];
	if(ret != -1) return ret;
	return ret = max({f(x - 1, y), f(x, y - 1)}) + a[x][y];	
}

void solve() {
	memset(cache, -1, sizeof(cache));
	cout << f(N, M) << '\n';	
}
int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) cin >> a[i][j];
	solve();
}
