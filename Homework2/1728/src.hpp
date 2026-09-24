#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
    //todo
    p = new int*[n];
    for(int i = 0 ; i < n ; i++){
        p[i] = nullptr;
    }
}
void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
    //todo
    int* curr_vector = p[x-1];
    //还没有加入东西
    if(curr_vector == nullptr){
        curr_vector = new int[8];
        //0放size
        curr_vector[0] = 8;
        curr_vector[1] = 0;
        p[x-1] = curr_vector;
    }
    // size = n，本来在下标n加新元素，现在得加2
    int insert_pos = curr_vector[1] + 2;
    int capacity = curr_vector[0];
    //下标最大是 size - 1.
    if(insert_pos > capacity - 1){
        //扩容。
        int new_size  = 2 * capacity;
        int* new_vector = nullptr;
        new_vector = new int[new_size];
        //复制
        new_vector[0] = new_size;
        for(int i = 1; i <= capacity - 1 ; i++){
            new_vector[i] = curr_vector[i];
        }
        //更新参数
        capacity = new_size;
        delete[] curr_vector;
        curr_vector = new_vector;
        p[x-1] = new_vector;
    }
    //插入
    curr_vector[insert_pos] = y;
    curr_vector[1]++;

}
int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
    //todo
    return p[x-1][k+1];
}
void Clear(int **&p,int n){//回收空间
    //todo
    for(int i = 0 ; i < n ; i++){
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
}