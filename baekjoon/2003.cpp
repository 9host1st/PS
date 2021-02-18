#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int a[10001], N, M, l, r, ans;
ll sum;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> a[i];
	while(1) {
		if(sum >= M) sum -= a[l++];
		else if(r == N) break;
		else sum += a[r++];
		if(sum == M) ans++;
	}
	cout << ans << '\n';
}
