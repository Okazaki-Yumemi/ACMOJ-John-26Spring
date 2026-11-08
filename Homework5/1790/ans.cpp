#include <bits/stdc++.h>

using namespace std;
const long long MOD1 = 1000000007LL;
const long long MOD2 = 1000000009LL;
int main(){
    long long n,m;

    cin >> n >> m;

    unordered_set<uint64_t> hashes;

    string s;
    cin >>s;

    const long long B = 27;

    long long max_B1 = 1;
    for(int i = 1 ; i < m ; i++){
        max_B1 = max_B1*B % MOD1;
    }

    long long max_B2 = 1;
    for(int i = 1; i < m ; i++){
        max_B2 = max_B2*B % MOD2;
    }

    long long init_hash1 = 0;
    long long init_hash2 = 0;


    for(long long i = 0 ; i < m ; i++){
        init_hash1 = (init_hash1 * B + (s[i] - 'a')) %MOD1;
    }

    for(long long i = 0 ; i < m ; i ++){
        init_hash2 = (init_hash2 * B + (s[i] - 'a')) %MOD2;
    }

    hashes.emplace((init_hash1<<32) | init_hash2);

    for(int i = m; i < n ; i++){
        long long removed1 = (s[i-m] - 'a') * max_B1 % MOD1;

        long long new_hash1 = (init_hash1 - removed1 + MOD1) % MOD1;

        long long removed2 = (s[i-m] - 'a') * max_B2 % MOD2;

        long long new_hash2 = (init_hash2 - removed2 + MOD2) % MOD2;

        new_hash1 = (new_hash1 * B + s[i] - 'a') % MOD1;
        new_hash2 = (new_hash2 * B + s[i] - 'a') % MOD2;
        hashes.emplace((new_hash1 <<32) |new_hash2);
        init_hash1 = new_hash1;
        init_hash2 = new_hash2;
    }


    std::cout<<hashes.size()<<'\n';

    return 0;
}