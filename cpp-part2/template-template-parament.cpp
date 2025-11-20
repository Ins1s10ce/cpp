// fuck 太难懂了 以后再看吧

#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <memory>
using namespace std;

// 模板中的一个参数也是模板 
/* example 1, 需要额外处理*/
template<typename T,
        template <typename U> // 不可以是T! U可以省略
			// 在模板中<>中, class和typename没有区别
            class Container 
        >
class XCls{
    private:
        Container<T> c;
	public:
		XCls() { cout << "XCls\n"; }
};

// 但是大部分Container不只需要一个参数
template<typename T>
// std::list完整类型定义
using Lst = list<T, allocator<T>>;

/* example 2, 有些SmartPtr只需要一个参数*/
template<typename T, 
			template <typename U>
                class SmartPtr
        >
class XCL{
    private:
        SmartPtr<T> sp;
    public:
        XCL() : sp(new T) { cout << "XCL\n"; }
};

/* 不是template template parameter*/
template <class T, class Sequence = deque<T>>
class stack {
    friend bool operator== <> (const stack&, const stack&);
    friend bool operator< <> (const stack&, const stack&);

    public:
        stack() { cout << "stack\n"; }

    protected:
        Sequence c;
};

int main() {
	
	// 希望声明一个list<string>, 更加灵活
    // 这里Lst未指定参数类型, 仍属于模板
    XCls<string, Lst> mylist1;

    // 只需要一个参数的智能指针
    XCL<string, shared_ptr> p1;

    // 这里list<int>已经不是模板, 所以不属于
    stack<int, list<int>> s;
    return 0;
}
