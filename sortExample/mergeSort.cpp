#include <bits/stdc++.h>
using namespace std;
int n;
void merge_sort(vector<int>& a, int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    vector<int> v2(r - l + 1);

    int L = l, R = mid + 1, idx = 0;
    while(L <= mid && R <= r) {
        if(a[L] <= a[R]) v2[idx++] = a[L++];
        else v2[idx++] = a[R++];
    }
    while(L <= mid) v2[idx++] = a[L++];
    while(R <= r) v2[idx++] = a[R++];

    for(int i = l; l <= r; l++) a[i] = v2[i - l];
}

int main() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    merge_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}
