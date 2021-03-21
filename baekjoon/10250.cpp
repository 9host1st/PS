#include <bits/stdc++.h>
using namespace std;
int T;
int H, W, N;
int ansH, ansW;
void solve() {
	while(T--) {
		cin >> H >> W >> N;
		if(N % H) {
			if(N / H + 1 >= 10) cout << N % H << N / H + 1 << '\n';
			else cout << N % H << "0" << N / H + 1 << '\n';
		} else {
			if(N / H >= 10) cout << H << N / H << '\n';
			else cout << H << "0" << N / H << '\n';
		}
	}
}
int main() {
	cin >> T;
	solve();
}
