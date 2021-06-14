#include <bits/stdc++.h>
using namespace std;
int N, a[101], ans;
int pCnt(int x) {
	int t = 0;
	for(int i = 1; i <= x; i++)
		if(x % i == 0) t++;
	return t;
}
void solve() {
	for(int i = 1; i <= N; i++) 
		if(pCnt(a[i]) == 2) ans++;	
	cout << ans;	
}
int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	solve();
}
