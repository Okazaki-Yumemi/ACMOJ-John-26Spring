#include <bits/stdc++.h>
typedef uint32_t u32;
using namespace std;
const u32 maxn = 2e7 + 2;


u32 n, a[maxn], seed;
inline u32 nextInteger(u32 x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

bool outputArr(void *a, u32 size) {
    if (size % 4) {
        return puts("-1"), 0;
    }

    u32 blocks = size / 4;
    u32 *A = (u32 *)a;
    u32 ret = size;
    u32 x = 23333333;
    for (u32 i = 0; i < blocks; i++) {
        ret = ret ^ (A[i] + x);
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
    }
    return printf("%u\n", ret), 1;
}

int main() {
    scanf("%d%d", &n, &seed);
    for (u32 i = 0; i < n; ++i) {
        seed = nextInteger(seed);
        a[i] = seed;
    }

    // TODO
    vector<vector<u32>> backets(256);
    for(u32 shift = 0 ; shift <= 24 ; shift += 8){
        for(u32 i = 0; i < n ; ++i){
            //拿出数做mask
            u32 bits = (a[i]>>shift) & 255u;

            backets[bits].push_back(a[i]);
        }
        //拷贝回去.
        int i = 0;
        while(i < n){
            for(int j = 0 ; j < 256; j++){
                vector<u32>& backet = backets[j];
                for(int z = 0 ; z < backet.size(); z++){
                    a[i] = backet[z];
                    i++;
                }
                backet.clear();
            }
        }
    }


    outputArr(a, n * sizeof(u32));
    return 0;
}