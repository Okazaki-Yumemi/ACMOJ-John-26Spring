#include <bits/stdc++.h>
using namespace std;


pair<int, int> partition(vector <int> &a, int pivot) {
    // TODO: implement partition
    int lt = 0;
    int gt = a.size() - 1;
    int i = 0;

    while(i <= gt){
        if(a[i] < pivot){
            swap(a[i],a[lt]);
            lt ++;
            i ++;
        }else if(a[i] == pivot){
            i ++;
        }else{
            swap(a[i],a[gt]);
            gt --;
        }
    }

    return {lt,gt + 1};
    
}

int main() {
    int n, pivot;
    cin >> n >> pivot;
    vector <int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    auto [l, r] = partition(arr, pivot);
    for (auto i : arr) cout << i << ' ';
    cout << '\n' << l << ' ' << r << '\n';
}