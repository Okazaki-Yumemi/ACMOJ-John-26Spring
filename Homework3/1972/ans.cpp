#include <bits/stdc++.h>

int main(){
    std::vector<int> hamming;
    int x;

    for(int i = 0 ; i < 256 ; i++){
        std::cin>>x;
        hamming.push_back(x);
    }

    int place = 0;

    for (int check = 1; check < 256; check *= 2) {
        int parity = 0;

        for (int j = 0; j < 256; j++) {
            if (j & check) {
                parity ^= hamming[j];
            }
        }

        if (parity) {
            place |= check;
        }
    }

    std::cout << place << '\n';
    return 0;

}