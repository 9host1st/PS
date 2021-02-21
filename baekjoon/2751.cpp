#include <bits/stdc++.h>
using namespace std;
int N;
int a2[1000001];
void merge(vector<int>& a, int l, int r)  {
    int mid = (l + r) / 2;
    int L = l;
    int R = mid + 1;
    int P = l;

    while(L <= mid && R <= r) {
        if(a[L] <= a[R]) a2[P++] = a[L++];
        else a2[P++] = a[R++];
    }
    if(L > mid) for(int i = R; i <= r; i++) a2[P++] = a[i];
    else for(int i = L; i <= mid; i++) a2[P++] = a[i];
    for(int i = l; i <= r; i++) a[i] = a2[i];
}

void mergeSort(vector<int>& a, int l, int r) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, r);
}
int main() {
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    mergeSort(a, 0, N - 1);
    for(int i = 0; i < N; i++) cout << a[i] << '\n';
}
