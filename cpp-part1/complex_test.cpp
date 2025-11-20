#include "complex.h"
#include <iostream>

using namespace std;

int main() {
    complex test(1,2);
    complex test1(1,2);
    cout << test.func(test1) << endl;
    test += test1;
    cout << test << test1 <<endl;
    test = test1 + 1.0;
    cout << test << endl;
    test = 1.0 + test1;
    cout << test << endl;
    test  = test + test1;
    cout << test << endl;
}

/*
Complex* pc = new Complex(1, 2);
等价于
Complex *pc;
1.分配内存
void* mem = operator new // 调用malloc(sizeof(Complex))
2. 转型
pc = static_cast<Complex*>(mem);
3. 构造函数
pc->Complex::Complex(1, 2); // Complex::Complex(pc(this), 1, 2);

delete ps;
等价于
1. 析构函数
String::~String(ps);
2. 释放内存
operator delete(ps); // 调用free(ps)

// 在VC中的内存动态分配情况
[notes](https://blog.csdn.net/WJwwwwwww/article/details/132335486)

array new/delete

*/
