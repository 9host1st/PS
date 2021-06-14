#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, a[51];
void solve() {
	sort(a, a + N);
	if(N==1) cout << a[0] * a[0] << '\n';
	else cout << a[0] * a[N - 1] << '\n';
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	solve();
}
