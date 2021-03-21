#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll x[1000001];
int main() {
	x[0] = 1;
	for(int i = 1; i <= 1000000; i++) x[(int)i] = (x[(int)(i - sqrt(i))] + x[(int)log(i)] + x[(int)(i * (sin(i) * sin(i)))]) % 1000000;
	while(1) {
		int a;
		cin >> a;
		if(a == -1) return 0;
		if(a == 0) cout << x[0] << '\n';
		else cout << x[a] % 1000000<< '\n';
	}
}
