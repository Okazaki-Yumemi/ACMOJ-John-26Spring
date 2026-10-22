#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

/* 
   NOTE:
   std::pow is for floating point numbers.
   For integers, it's better to implement one.
*/

// FIXME: reimplement with long long int
long long int pow_2 (int x) {
    return  1LL * x * x;
}

struct point {
    int x, y;
    point (int _x, int _y) : x(_x), y(_y) {}
    long long distance_2 (const point & other) const {
        const long long dx = static_cast<long long>(x) - other.x;
        const long long dy = static_cast<long long>(y) - other.y;
        return dx * dx + dy * dy;
    }
};

long long solve (vector <point> &a, int l, int r) {
    // TODO: implement solve    
    if(l + 1 >= r){
        return INF; // infinity
    }

    int mid = l + (r - l)/2;
    long long ret = min(solve(a,l,mid),solve(a,mid,r));

    vector<point> strip;
    //开始归并
    for(int i = l ; i < r ; i++){
        if(pow_2((a[i].x - a[mid].x)) < ret){
            strip.push_back(a[i]);
        }
    }
    //
    auto cmp = [&](const point& a,const point& b) -> bool {
        if(a.y > b.y){
            return true;
        }else{
            return false;
        }
    };
    sort(strip.begin(),strip.end(),cmp);

    for(int i = 0 ; i < strip.size(); i++){
        for(int j = i+1 ; j < strip.size() ; j++){
            if(pow_2(strip[i].y - strip[j].y) >= ret){
                break;
            }
            ret = min(ret, strip[i].distance_2(strip[j]));
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector <point> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return u.x < v.x;
    });
    cout << solve (a, 0, n) << endl;
}
