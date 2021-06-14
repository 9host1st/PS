#include <bits/stdc++.h>
using namespace std;
int M, N;
bool a[1000001];
void solve() {
	a[1] = true;
	for(int i = 2; i * i <= 1000000; i++)
		for(int j = i + i; j <= 1000000; j += i)
			a[j] = true;
	for(int i = M; i <= N; i++)
		if(!a[i]) cout << i << '\n';
}
int main() {
	cin >> M >> N;
	solve();
}
