#include <iostream>
#include <vector>
using namespace std;

// 传统方法, 只能in_addr<int>::type
template <typename T>
struct in_addr { // struct可以接收模板参数, typedef不能
    typedef vector<T, MyAlloc<T>> type; // 编译器看到typedef时, 会将其替换为具体类型
};  

// c++11 alias template, 可以接收参数的别名
template <typename T>
using Vec = vector<T, MyAlloc<T>>;

// define不能达到相同效果
// Vec<int> = template<typename int> vector<int, MyAlloc<int>>; // 错误用法
template<typename T>
#define Vec<T> vector<T, MyAlloc<T>>;

// typedef不能接收参数
typdef vector<int, MyAlloc<int>> IntVec; // 只能定义具体类型

int main() {
    // 等价于vector<int, MyAlloc<int>> coll;
    Vec<int> coll;
}
