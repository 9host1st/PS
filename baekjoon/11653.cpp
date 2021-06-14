#include <bits/stdc++.h>
using namespace std;
int N;
void solve() {
	for(int i = 2; i <= N; i++) {
		while(N % i == 0) {
			N /= i;
			cout << i << '\n';
		}
	}
}
int main() {
	cin >> N;
	solve();
}
