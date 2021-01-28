#include <bits/stdc++.h>
using namespace std;
int k;
vector<char> a;
void solve() {
	vector<int> v(11);
	for(int i = 0; i < 10; i++) v[i] = i;
	do {
		bool chk = true;
		set<int> t;
		for(int i = 0; i < k; i++) {
			if(a[i] == '<') {
				if(v[i] >= v[i + 1]) {
					chk = false;
				} else {
					cout << v[i] << ' ' << v[i + 1] << '\n';
				}
			}
		    if(a[i] == '>') {
				if(v[i] <= v[i + 1]) {
					chk = false;	
				} else {
					cout << v[i] << ' ' << v[i + 1] << '\n';
				}
			}
		}
	} while(next_permutation(v.begin(), v.end()));
}
int main() {
	cin >> k;
	for(int i = 0; i < k; i++) {
		char tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	solve();
}
