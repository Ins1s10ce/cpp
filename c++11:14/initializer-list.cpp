#include <iostream>
// #include <initializer_list>
using namespace std;

// 支持函数接受任意个数的参数
// vector<int> v{1,2,3,4,5,6};
// 的实现原理就是将{1,2,3,4,5}包装成initializer_list 调用参数是initializer_list的ctor
void print(initializer_list<int> vals) {
    for (auto p = vals.begin(); p!=vals.end(); ++p) {
        cout << *p << ' ';
    }
    cout << endl;
}

class P{
public:
    // 将initializer_list分解
    P(int a, int b){
        cout << "P(int a,int b)=" <<a << ' ' << b << endl;
    };
    // 将整个参数列表包装成initializer_list
    // initlist_list内部包括一个指向数组头部的指针和数组的大小 (拷贝时浅拷贝)
    P(initializer_list<int> initlist) {
        cout << "P(initializer_list<int>)=";
        for(auto i : initlist) {
            cout << i << ' ';
        }
        cout << endl;
    }
};

int main() {
    print({1,2,3,4,5,6,7});

    P p(77,5);
    // 生成initializer_list 调用对应的构造函数
    P q{77,5};
    // 这里只有第一个构造函数没有第二个构造函数时会失败
    P r{77,5,23};
    // 右边是initializer_list, 不会调用拷贝构造
    P s = {77, 5};
}
