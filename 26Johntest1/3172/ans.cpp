
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Box {
    ll x1, y1, x2, y2;
    ll z;  // 最前面的 z 坐标
};

int main() {
    int n;
    cin >> n;

    vector<Box> a(n);
    vector<ll> xs, ys;
    // 处理数据
    for (int i = 0; i < n; i++) {
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        a[i] = {
            min(x1, x2), min(y1, y2),
            max(x1, x2), max(y1, y2),
            min(z1, z2)
        };

        xs.push_back(a[i].x1);
        xs.push_back(a[i].x2);
        ys.push_back(a[i].y1);
        ys.push_back(a[i].y2);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    ll ans = 0;

    // 1. 检查水平线段
    for (ll y : ys) {
        for (int j = 0; j + 1 < (int)xs.size(); j++) {
            ll L = xs[j], R = xs[j + 1];

            ll nearest = LLONG_MAX;
            bool visible = false;

            for (const auto& b : a) {
                // 这个矩形是否覆盖当前线段
                if (b.x1 <= L && R <= b.x2 &&
                    b.y1 <= y && y <= b.y2) {

                    bool on_edge = (y == b.y1 || y == b.y2);

                    if (b.z < nearest) {
                        nearest = b.z;
                        visible = on_edge;
                    } else if (b.z == nearest) {
                        visible |= on_edge;
                    }
                }
            }

            if (visible) ans += R - L;
        }
    }

    // 2. 检查竖直线段
    for (ll x : xs) {
        for (int j = 0; j + 1 < (int)ys.size(); j++) {
            ll L = ys[j], R = ys[j + 1];

            ll nearest = LLONG_MAX;
            bool visible = false;

            for (const auto& b : a) {
                if (b.y1 <= L && R <= b.y2 &&
                    b.x1 <= x && x <= b.x2) {

                    bool on_edge = (x == b.x1 || x == b.x2);

                    if (b.z < nearest) {
                        nearest = b.z;
                        visible = on_edge;
                    } else if (b.z == nearest) {
                        visible |= on_edge;
                    }
                }
            }

            if (visible) ans += R - L;
        }
    }

    cout << ans << '\n';
}
