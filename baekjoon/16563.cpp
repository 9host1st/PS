#include <bits/stdc++.h>
using namespace std;
int N, t;
bool a[5000001];
vector<int> p;
int minFactor[5000001];
void solve() {
    for(int i =2 ; i <= 5000000; i++) minFactor[i] = i;
    for(int i =2; i * i <= 5000000; i++) {
        if(minFactor[i] == i) {
            for(int k = i * i; k <= 5000000; k += i) {
                if(minFactor[k] == k) minFactor[k] = i;
            }
        }
    }
    while(N--) {
        cin >> t;
        while(t > 1) {
            cout << minFactor[t] << ' ';
            t /= minFactor[t];
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    solve();
}