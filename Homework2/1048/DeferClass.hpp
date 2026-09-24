#include<functional>
#include<vector>
#include <utility>

class Defer{

private:
    std::vector<std::function<void()>> functions;

public:

    Defer(std::function<void()> f){
        functions.push_back(std::move(f));
    }

    void operator() (std::function<void()> f){
        functions.push_back(std::move(f));
    }

    ~Defer(){
        while(!functions.empty()){
            auto f = std::move(functions.back());
            functions.pop_back();
            f();
        }
    }

    Defer(const Defer&) = delete;

    Defer& operator=(const Defer&) = delete;


};