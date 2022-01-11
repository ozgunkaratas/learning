
#include <iostream>

using namespace std;

namespace this_namespace {
    void func() {
        cout << "this is happening from this_namespace" << endl;
    }
}

namespace that_namespace {
    void func() {
        cout << "this is happening from that_namespace" << endl;
    }
}

namespace this_namespace {
    void discont_func() {
        cout << "i opened this_namespace and wrote something in it later on" << endl;
    }

}

namespace outer_nest {
    void outer_func() {
        cout << "this is happening on outer func from outer_nest" << endl;
    }
    namespace inner_nest{
    void inner_func() {
        cout << "this is from inner_func on inner_nest" << endl;
    } 
}
}

int main()
{
    std::cout << "Hello World!\n";
    this_namespace::func();
    that_namespace::func();
    this_namespace::discont_func();
    outer_nest::outer_func();
    outer_nest::inner_nest::inner_func();

}
