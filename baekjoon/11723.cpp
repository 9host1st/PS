#include <bits/stdc++.h>
using namespace std;
int M;
string s, k;
void solve() {
	int ret = 0;
	int res;
	while(M--) {
		cin >> s;
		if(s == "add") {
			cin >> res;
			ret |= (1 << res);
		} else if(s == "remove") {
			cin >> res;
			ret &= ~(1 << res);
		} else if(s == "check") {
			cin >> res;
			if(ret & (1 << res)) cout << "1" << '\n';
			else cout << "0" << '\n';
		} else if(s == "toggle") {
			cin >> res;
			ret ^= (1 << res);
		} else if(s == "all") {
			ret = (1 << 21) - 1;
		} else if(s == "empty") {
			ret = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M;
	solve();
}
