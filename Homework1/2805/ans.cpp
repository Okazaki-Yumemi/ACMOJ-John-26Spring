#include <bits/stdc++.h>
using namespace std;

int count_factor(int x, int num) {
    int n = 0;
    while (x % num == 0) {
        n++;
        x /= num;
    }
    return n;
}

int main() {
    int n, k;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    vector<int> cnt_2(n), cnt_5(n);

    long long total2 = 0;
    long long total5 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt_2[i] = count_factor(x, 2);
        cnt_5[i] = count_factor(x, 5);

        total2 += cnt_2[i];
        total5 += cnt_5[i];
    }

    // 原数组自己都不足 k 个 0，删除只会更少
    if (total2 < k || total5 < k) {
        cout << 0 << '\n';
        return 0;
    }

    long long limit2 = total2 - k;
    long long limit5 = total5 - k;

    long long sum2 = 0, sum5 = 0;
    long long ans = 0;

    int p = 0;

    for (int q = 0; q < n; q++) {
        sum2 += cnt_2[q];
        sum5 += cnt_5[q];

        while (sum2 > limit2 || sum5 > limit5) {
            sum2 -= cnt_2[p];
            sum5 -= cnt_5[p];
            p++;
        }

        ans += q - p + 1;
    }

    cout << ans << '\n';

    return 0;
}