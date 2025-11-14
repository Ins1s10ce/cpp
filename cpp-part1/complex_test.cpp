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
void* mem = operator new(malloc(sizeof(Complex)));
2. 转型
pc = static_cast<Complex*>(mem);
3. 构造函数
pc->Complex::Complex(1, 2);
*/
