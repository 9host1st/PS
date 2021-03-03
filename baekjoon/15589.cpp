#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
vector<pii> a;
int N;
int solotime[100001], totaltime;
int main() {
	cin>> N;
	for(int i = 1; i <= N; i++) {
		int s, e; cin >> s >> e;
		a.push_back({s, i});
		a.push_back({e, -i});
	}
	sort(a.begin(), a.end());
	int peo = 0, sumnum = 0;
	peo += (a[0].second > 0?1:-1);
	sumnum += a[0].second;
	for(int i = 1; i < a.size(); i++) {
		int T = a[i].first - a[i - 1].first;
		if(peo == 1) solotime[sumnum] += T;
		if(peo >= 1) totaltime += T;
		peo += (a[i].second > 0?1:-1);
		sumnum += a[i].second;
	}
	int minsolotime = 2e9;
	for(int i = 1; i<= N; i++) minsolotime=min(minsolotime, solotime[i]);
	cout << totaltime - minsolotime; 
}
