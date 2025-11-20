#ifndef __SINGLENTON__
#define __SINGLENTON__

#include <iostream>
using namespace std;

class Singlenton {
public:
    static Singlenton& getInstance();
    void setup() {
        cout << "setuping"<< endl;
    };
private:
    Singlenton(){cout<<"create"<<endl;};
    Singlenton(const Singlenton& rhs);
};

Singlenton& Singlenton::getInstance() {
    // 只有调用的时候才创建这个静态的对象 多次调用也只是返回一个
    // static变量只会初始化一次, 这里定义后调用构造函数创建对象
    static Singlenton s;
    return s;
}

#endif
