#include <bits/stdc++.h>
using namespace std;
int N, a[1000001], ans;
queue<int> q;
void solve(){
	for(int i = 1; i + 2 < N; i++) 
		if(a[i] == 1 && (a[i - 1] ^ a[i + 2])) q.push(i);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		a[cur] = 0;
		ans++;
		if(a[cur - 3] > 0 && (a[cur - 3] ^ a[cur])) {
			q.push(cur - 2);
		} if(a[cur + 3] < N && (a[cur] ^ a[cur + 3])) {
			q.push(cur + 1);
		}
	}
	cout << ans << '\n';
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	solve();
}
