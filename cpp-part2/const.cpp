#include <iostream>
#include "../c++/string.h"

using namespace std;

/*  about const
顶层const: 修饰变量本身, 不影响函数签名 (比如int* const p, 传参时指针类型不变仍为int*, 影响的是函数内部)
底层const: 修饰变量指向的数据, 影响函数签名 (比如const int* p, 传参时指针类型变为const int*, 与int*不同)
成员函数末尾的const: 修饰this指针, 影响函数签名 (class A中非const成员函数this类型为A*, const成员函数this类型为const A*)
*/

template<typename T>
class complex {
public:
    complex(T r = 0, T i = 0) :re(r), im(i){};
    // const 只能修饰成员函数 不能修饰全局函数
    // const 表示成员函数不会修改数据 只会读取数据
    // 其中const会影响函数签名

    // #1 non-const object 可以调用const member function, 反之不行
    // 一个非const对象（T*）可以安全地隐式转换为const对象（const T*），但反过来则不行

    // #2 当成员函数的const和non-const版本都存在的时候
    // const对象只能调用const版本
    // non-const对象只能调用non-const版本
    T real() {return im;}
    T real() const {return im;} // 必须考虑COW (copy on write)
private:
    T re, im;
};

int main() {
        const String str("test");
    // 'this' argument to member function 'print' has type 'const String', but function is not marked const
    // str.print(); // 该行报错 因为str是const表示这个对象不会修改成员变量 但是print函数没有被const修饰 有可能会修改成员变量
                    // 所以导致了错误
}
