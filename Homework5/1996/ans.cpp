#include<bits/stdc++.h>

using namespace std;

using u32 = uint32_t;

constexpr u32 ADD = 0xe6546b64u;
constexpr u32 MUL = 0xc2b2ae35u;

// MUL为mod 2^32 的乘法逆元
constexpr u32 INV_MUL = 0x7ed1b41du;

// 32位左
u32 rotl(u32 x, int k){
    return (x <<k) | (x >>(32 - k));
}

//32 right
u32 rotr(u32 x, int k){
    return (x >> k) | (x << (32 - k));
}

// MIX
u32 mix(u32 h, u32 d) {
    d = rotl(d, 15);
    h ^= d;
    h = rotl(h, 13);
    h += ADD;
    return h;
}

u32 inverse_final_mix(u32 h) {

    // 撤销最后一次 h ^= h >> 16
    h ^= h >> 16;

    // 撤销乘法
    h *= INV_MUL;

    // 撤销 h ^= h >> 13
    h ^= h >> 13;
    h ^= h >> 26;

    // 撤销最开始的 h ^= h >> 16
    h ^= h >> 16;

    return h;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    u32 target;
    int n ;
    cin >> target >> n;

    // 主动构造前 n-1 输入为 0

    u32 h = 0;

    for(int i = 0 ; i <  n - 1; i++){
        cout << 0 << ' ';
        h = mix(h, 0);
    }

    //从目标恢复最后一次mix的状态
    u32 h_last = inverse_final_mix(target);
    
    //第三步，逆转最后一次mix
    u32 after_xor = rotr(h_last -ADD, 13);
    u32 last = rotr(after_xor^ h, 15);

    cout<<last<<'n';

    return 0;
}