template <typename... Args>
void debugPrint(const Args&... args){
    bool first = true;
    
    auto printOne = [&](const auto& arg){
        if(first){
            std::cout<<arg;
            first = false;
        }else{
            std::cout<<" "<<arg;
        }
    };
    
    ((printOne(args)),...);
    std::cout<<"\n";
}