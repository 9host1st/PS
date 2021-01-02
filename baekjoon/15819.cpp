#include <bits/stdc++.h>
using namespace std;
int N, l;
vector<string> s;
int main()  {
    cin >> N >> l;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(), s.end());

    cout << s[l - 1] << '\n';
}
