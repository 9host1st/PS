#include <bits/stdc++.h>;
using namespace std;
using pii=pair<int,int>;
int N, T, G;
bool vis[200001];
queue<pii> q;
int f(int t) {
    if(t == 0) return t;
    vector<int> v;
    string tmp = to_string(t);
    int decimal = 1;
    int tot = 0;
    v.push_back((tmp[0] - '0') - 1);
    for(int i = 1; i < tmp.size(); i++) v.push_back(tmp[i] - '0');
    reverse(v.begin(), v.end());
    for(auto& it : v) {
        tot += it * decimal;
        decimal *= 10;
    }
    return tot;
}
int main () {
    cin >> N >> T >> G;
    q.push({N, 0}); vis[N] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int t = cur.first;
        int cnt = cur.second;
        if(cnt > T) {
            cout << "ANG" << '\n';
            return 0;
        } if(t == G) {
            cout << cnt << '\n';
            return 0;
        }
        if((t + 1 <= 99999) && !vis[t + 1]) {
            q.push({t + 1, cnt + 1});
            vis[t + 1] = 1;
        }
        int res = f(t * 2);
        if(t * 2 <= 99999 && !vis[res]) {
            q.push({res, cnt + 1});
            vis[res] = 1;
        }
    }
    cout << "ANG" << '\n';
}
