#include <bits/stdc++.h>
using namespace std;
using pii = pair<double, double>;
vector<double> X, Y;
vector<pii> v;
pair<pii, pii> a[31];
int M[65][65];
int N;
double area;
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
		a[i].second.first += a[i].first.first;
		a[i].second.second += a[i].first.second;
		X.push_back(a[i].first.first);
		X.push_back(a[i].second.first);
		Y.push_back(a[i].first.second);
		Y.push_back(a[i].second.second);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	for(int i = 0; i < N; i++) {
		a[i].first.first = lower_bound(X.begin(), X.end(), a[i].first.first) - X.begin();
		a[i].second.first = lower_bound(X.begin(), X.end(), a[i].second.first) - X.begin();
		a[i].first.second = lower_bound(Y.begin(), Y.end(), a[i].first.second) - Y.begin();
		a[i].second.second = lower_bound(Y.begin(), Y.end(), a[i].second.second) - Y.begin();
		int minX = min(a[i].first.first, a[i].second.first);
		int maxX = max(a[i].first.first, a[i].second.first);
		int minY = min(a[i].first.second, a[i].second.second);
		int maxY = max(a[i].first.second, a[i].second.second);
		for(int j = minX; j < maxX; j++) {
			for(int k = minY; k < maxY; k++) M[j][k] = 1;
		}
	}
	for(int i = 0; i < 60; i++)
	for(int j = 0; j < 60; j++) {
		if(M[i][j] == 1) {
			area += (X[i + 1] - X[i])*(Y[j + 1] - Y[j]);
		}
	}
	printf("%.2lf", area);
}
