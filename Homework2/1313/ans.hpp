// "Wrapper": src.hpp
#ifndef Wrapper_CPP_Wrapper_HPP
#define Wrapper_CPP_Wrapper_HPP

#include <string>

using Func = void (*)(std::string);
using Hook = void (*)();

struct Wrapper {
    // todo: add definitions here
    //原函数
    Func foo;

    //before
    Hook before;

    //after
    Hook after;

    Wrapper* prev;
    Wrapper* next;

};
// todo: add definition for link list
inline Wrapper* head = nullptr;
inline Wrapper* tail = nullptr;



// todo: create()
Wrapper* create(
    Func foo,
    Hook before,
    Hook after
){
    Wrapper* wrp = new Wrapper;
    wrp ->prev = nullptr;
    wrp ->next = nullptr;
    wrp->foo = foo;
    wrp->after = after;
    wrp->before = before;

    if(head == nullptr){
        head = wrp;
        wrp->next = tail;
        wrp->prev = nullptr;
        tail = wrp;

    }else{
        tail->next = wrp;
        wrp->prev = tail;
        tail = wrp;
    }
    return wrp;

}

// todo: remove()
void remove(Wrapper* g){
    if(g->prev == nullptr){
        head = g->next;
    }
    if(g->next == nullptr){
        tail = g->prev;
    }
    if(g->prev != nullptr){
        g->prev->next = g->next;
    }
    if(g->next != nullptr){
        g->next->prev = g->prev;
    }
    delete g;    
}

// todo: run()
void run(Wrapper* g,std::string s){
    g->before();
    g->foo(s);
    g->after();
}
// todo: destroy()
void destroy(){
    Wrapper* ptr = head;
    
    while(ptr != nullptr && ptr->next != nullptr){
        Wrapper* next = ptr->next;
        delete ptr;
        ptr = next;
    }
    delete ptr;
    head = nullptr;
    tail = nullptr;
}

#endif //Wrapper_CPP_Wrapper_HPP