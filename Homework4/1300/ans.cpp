#include <bits/stdc++.h>
using namespace std;

#include <random>
#include <chrono>
// use precise time as random seed
const int RANDOM_SEED = chrono::system_clock::now().time_since_epoch().count();
mt19937 rng(RANDOM_SEED); // random number generator

int n, k;
vector <int> a;

int randint(int l, int r) { // rand in [l, r]
    return int(rng() % (r - l + 1) + l);
}

int quick_select(int l , int r){
    if(l == r){
        return a[l];
    }
    int pivot_index = randint(l,r);
    int pivot = a[pivot_index];
    int lt = l;
    int gt = r;
    int i = l;
    int target = k - 1;
    
    while(i <= gt){
        if(a[i] < pivot){
            swap(a[i],a[lt]);
            lt++;
            i++;
        }else if(a[i] == pivot){
            i++;
        }else{
            swap(a[i],a[gt]);
            gt --;
        }
    }

    if(target < lt){
        return quick_select(l, lt - 1);
    }else if(target >= lt && target <= gt){
        return pivot;
    }else{
        return quick_select(gt + 1,r);
    }
}




void read_input_data_vector() {
    int m;
    cin >> n >> k >> m; a.resize(int(4e7) + 9);
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    unsigned int z = a[m - 1];
    for (int i = m; i < n; i++) {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}

int main(){
    read_input_data_vector();

    std::cout<<quick_select(0,n - 1)<<endl;
}