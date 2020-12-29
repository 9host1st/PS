#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double>> a;
int t;
double ans;
int main() {
    cin >> t;
    for(int i = 1; i <= t; i++) {
        double x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    for(int i = 0; i < t; i++) {
        if(i == t - 1) 
            ans += ((a[i].first + a[0].first)*(a[i].second - a[0].second));
        else
            ans += ((a[i].first + a[i + 1].first) * (a[i].second - a[i + 1].second));
    }
    ans = abs(ans) * 0.5;

    printf("%.1f", ans);
}
