#include <iostream>
using namespace std;

// pointer-like class, 需要重载*和->运算符

// 智能指针
template<class T>
class my_shared_ptr {
public:
    T& operator*() const {
        return *px;
    }

    T* operator->() const {
        return px;
    }

    my_shared_ptr(T* p): px(p) {}
private:
    T* px;
    long* pn;
};

// 迭代器, 还需要重载++和--运算符
template<class T, class Ref, class Ptr>
struct __list_iterator { // 链表迭代器
    // 别名, 指代本类
    typedef __list_iterator<T, Ref, Ptr>  self;
    typedef Ptr pointer;
    typedef Ref reference;
    // 节点类
    typedef __list_node<T>* link_type;
    // 指向节点的指针
    link_type node;
    bool operator==(const self& x) const {
        return node == x.node;
    }
    bool operator!=(const self& x) const {
        return node != x.node;  
    }
    reference operator*() const {
        return (*node).data;
    }
    pointer operator->() const {
        // 返回指向节点数据的指针
        return &(operator*());
    }
    // 前置++
    self& operator++() {
        node = (link_type)(node->next);
        return *this;
    }
    // 后置++
    self operator++(int) {
        self tmp = *this;
        ++*this; // 再进行前置++
        return tmp; // 返回旧值
    }
    self& operator--() {
        node = (link_type)(node->prev);
        return *this;
    }   
    self operator--(int) {
        self tmp = *this;
        --*this;
        return tmp;
    }       
};
