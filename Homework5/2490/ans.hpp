#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <string>

class RollingHash {
private:
    long long p1,p2;
    // 在这里添加你需要的私有成员变量和函数
    std::string s;
    long long size;

    std::vector<long long> H_1;
    std::vector<long long> H_2;

    std::vector<long long> power1;
    std::vector<long long> power2;
    
public:
 RollingHash(){
     //初始化你的class
    p1 = 1e9 + 7;
    p2 = 1e9 + 9;
    H_1.push_back(0);
    H_2.push_back(0);
    power1.push_back(1);
    power2.push_back(1);
    size = 0;
 };

~RollingHash(){};
std::pair<long long, long long> getp(){
    return std::pair<long long, long long> (p1,p2);
};
// 将字符c 追加到字符串末尾
void append(char c){
    s.push_back(c);
    size++; // size -> 1
    H_1.push_back((H_1[size-1]* 131 + (c - 'a' + 1))%p1);
    H_2.push_back((H_2[size-1]* 131 + (c - 'a' + 1))%p2);
    power1.push_back(power1[size-1]*131 % p1);
    power2.push_back(power2[size-1]*131 % p2);
}        

// 获取从位置l 到位置r 的子串的哈希值（1-based索引）
// 返回一个包含两个long long 的pair，分别是两个模数下的哈希值
std::pair<long long, long long> getHash(int l, int r){
    long long hash_1 =( H_1[r] - H_1[l-1]*power1[r-l+1]%p1 + p1)%p1;
    long long hash_2 =( H_2[r] - H_2[l-1]*power2[r-l+1]%p2 + p2)%p2;
    std::pair<long long, long long> ans = std::pair(hash_1,hash_2);
    return ans ;
}
};
#endif