#include <bits/stdc++.h>
using namespace std;
int N, x;
vector<int> a, b;
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> x;
		a.push_back(x);
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for(int i = 0; i < N; i++) cout << lower_bound(a.begin(), a.end(), b[i]) - a.begin() << ' ';
	
}
