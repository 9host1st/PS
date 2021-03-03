#include <bits/stdc++.h>
using namespace std;
int N, M;
unordered_map<string, string> m;
string addr, pass;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	while(N--) {
		cin >> addr >> pass;
		m.insert({addr, pass});
	}
	while(M--) {
		cin >> addr;
		auto item = m.find(addr);
		cout << item -> second << '\n';
	}
}
