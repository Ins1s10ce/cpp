#include <iostream>
using namespace std;

// 仿函数 一个类重载()符号之后 表现的像函数
template <class Container<T> 
struct identity : public unary_function<T, T> { // base class: todo
    const T& operator()(const T& x) const {
        return x;
    }
};

template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair(const T1& a, const T2& b) : first(a), second(b) {}
};


template <class Pair>
struct select1st : public unary_function<Pair, typename Pair::first_type> {
    // 表明这是一个类型
    const typename Pair::first_type&
    const typename Pair::first_type& operator()(const Pair& x) const {
        return x.first;
    }
};

template <class Pair>
struct select2nd : public unary_function<Pair, typename Pair::second_type> {
    const typename Pair::second_type& operator()(const Pair& x) const {
        return x.second;
    }
};

int main() {

}
