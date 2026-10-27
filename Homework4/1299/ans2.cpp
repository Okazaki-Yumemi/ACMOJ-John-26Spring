#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

/* 
   NOTE:
   std::pow is for floating point numbers.
   For integers, it's better to implement one.
*/

// FIXME: reimplement with long long int
long long pow_2 (long long x) {
    return x * x;
}

struct point {
    int x, y;
    point (int _x, int _y) : x(_x), y(_y) {}
    long long distance_2 (const point & other) const {
        // TODO: implement distance_2
        long long x1 = (long long)x;
        long long x2 = (long long)other.x;
        long long y1 = (long long)y;
        long long y2 = (long long)other.y;

        return pow_2(x1-x2) + pow_2(y1 - y2);
    }
};

long long solve (vector <point> &a, int l, int r) {
    // TODO: implement solve    
    if(l + 1 >= r){
        return INF;
    }
    // [ )
    int mid = l + (r- l)/2;
    int midX = a[mid].x;
    long long ret = min(solve(a,l,mid),solve(a,mid,r));

    // 按照y排序;
    int left = l;
    int right = mid;
    vector<point> helper;
    helper.reserve(r-1);
    while(left < mid && right < r){
        if(a[left].y <= a[right].y){
            helper.push_back(a[left]);
            left ++;
        }else{
            helper.push_back(a[right]);
            right ++;
        }
    }

    while (left < mid)
    {
        helper.push_back(a[left]);
        left ++ ;
    }

    while(right < r){
        helper.push_back(a[right]);
        right ++;
    }
    for(int i = 0 ; i < helper.size() ;i++){
        a[i+l] = helper[i]; 
    }
    vector<point> strip;
    strip.reserve(r-1);
    for(int i = l ; i < r ; i++){
        if(pow_2(a[i].x - midX) <= ret){
            strip.push_back(a[i]);
        }
    }
    

    for(int i = 0; i <strip.size(); i++){
        for(int j = i+1 ; j < strip.size() ; j++){
            if(pow_2(strip[i].y - strip[j].y) >= ret){
                break;
            }
            ret = min(ret,strip[i].distance_2(strip[j]));
        }
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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