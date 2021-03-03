#include <bits/stdc++.h>
using namespace std;
string s;
int N;
void solve() {
    int cnt = 0;
    int tmp = 665;
    while(++tmp) {
        s = to_string(tmp);
        if(s.find("666") != -1) ++cnt;
        if(cnt == N) {
            cout << tmp << '\n';
            break;
        }
    }
}
int main() {
    cin >> N;
    solve();
}
