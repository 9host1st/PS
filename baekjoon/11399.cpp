#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
int N, x;
ll ans;
ll a[1001];
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	for(int i = 0; i < N; i++) 
		ans += a[i] * (N - i);
	cout << ans;
}
