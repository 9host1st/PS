#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int N, ans, res;
void solve() {
	if(N <= 3) {
		cout << "0";
		return;
	}
	for(int i = 0; i < N; i += 4) {
		res = 0;
		for(int j = 0; j < 4; j++) {
			if(a[i + j] == 0) res++;
		} 
		if(res == 3) {
			for(int j = 0; j < 4; j++) {
				if(a[i + j] == 1) {
					a[i + j] = 0;
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	solve();
}
