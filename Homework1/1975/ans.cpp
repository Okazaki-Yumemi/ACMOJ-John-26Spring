#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p;

    vector<long long> grades(n);

    for (int i = 0; i < n; i++) {
        cin >> grades[i];
    }

    vector<long long> diff(n + 1, 0);

    for (int i = 0; i < p; i++) {
        int x, y;
        long long z;

        cin >> x >> y >> z;
        if(x > y){
            swap(x,y);
        }
        diff[x-1] += z;
        diff[y] -= z;
    }

    // 前缀和
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }

    long long mn = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        mn = min(mn, grades[i] + diff[i]);
    }

    cout << mn << '\n';

    return 0;
}