#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int x, a[30001], p, l;
int t;
vector<pii> ans;
int b[30001];
int main() {
    int x;
    cin >> x;
    a[1] = x;
    for(int i = 1; i <= 30000; i++) {
        memset(a, 0, sizeof(a));
        a[1] = x;
        int k = 1;
        k++;
        a[2] = i;
        p = 2;
        while(true) {
            p++;
            a[p] = a[p - 2] - a[p - 1];
            if(a[p] < 0) break;
            k++;
        }
        l = k;
        ans.push_back({l, i});
    }
    sort(ans.begin(), ans.end(), greater<>());

    cout << ans[0].first << '\n';
    b[1] = x;
    b[2] = ans[0].second;
    p = 2;
    cout << b[1] << ' ' << b[2] << ' ';
    while(true) {
        p++;
        if(b[p - 2] - b[p - 1]< 0) break;
        b[p] = b[p - 2] - b[p - 1];
        cout << b[p] << ' ';
    }
}
