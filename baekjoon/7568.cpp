#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
int N, x, y, ans[51];
vector<pii> v;
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j != i) {
                if(v[j].first > v[i].first && v[j].second > v[i].second) ans[i] ++;
            }
        }
    }
    for(int i = 0; i < N; i++) cout << ans[i]+1 << '\n';
}
