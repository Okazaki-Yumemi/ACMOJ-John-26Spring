#include <bits/stdc++.h>

int main(){
    unsigned int n ;
    std::cin>> n;

    //高16位置
    unsigned int x = n>>16;
    //低16位
    unsigned int y = n<<16;

    std::cout<<(x|y)<<std::endl;

}