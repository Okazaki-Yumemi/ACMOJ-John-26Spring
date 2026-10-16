#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n+2);
    
    int left = 1;
    int right = n;


    while(left < right){
        int mid = left + (right - left)/ 2;

        std::cout<<"0 "<<mid<<std::endl;

        std::cin>>a[mid];

        std::cout<<"0 "<<mid + 1 <<std::endl;

        std::cin>>a[mid+1];

        if(a[mid] > a[mid + 1]){
            left = mid + 1;
        }else{
            right = mid;
        }
        
    }
    std::cout << "1 " << left << std::endl;

    return 0;
}