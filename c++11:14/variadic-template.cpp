#include <iostream>

/* 例一: 递归调用print */
// 递归解包
// 优先调用特化的函数
void printX() {
    std::cout << std::endl;
}
// 更加泛化
template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
    std::cout << firstArg << std::endl;
    std::cout << "left: " << sizeof...(args) << " params" << " ";
    // args 会被分为2部分 一部分是第一个参数 第二部分是args...
    printX(args...);
}


/* 例二: 重写prinf */ 
// 参数为一个char*时调用, 递归出口
void printF(const char *s) {
    while(*s) {
        if(*s=='%'&&*(++s)!='%')
            throw std::runtime_error("invalid format string");
        std::cout << *s++;
    }
}

//printf
template<typename T, typename... Args>
void printF(const char* s, T value, Args... args) {
    while(*s) {
        if(*s=='%'&&*(++s)!='%') {
            std::cout << value;
            printF(++s, args...);
            return;
        }
        std::cout << *s++;
    }
    throw std::runtime_error("invalid format string");
}

/* 例三: 初始化列表实现maximum */
cout << max({1,2,3,4,5}) << endl;

/* 例四: 多参数maximum */
int maximum(int n) {return n;}

template<typename...Args>
int maximum(int n, Args... args) {
    return std::max(n, maximum(args...));
}

/* 例五: 类模板实现偏特化, 特殊处理头尾元素*/
template <typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}

template<int IDX, int MAX, typename.. Args>
struct PRINT_TUPLE {
    static void print(ostream& os, const tuple<Args...>& t) {
        os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
    }
};

tmeplate<int MAX, typename.. Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
    static void print(ostream& os, const tuple<Args...>& t) {
        // 递归出口
    }
};

/* 例六: tuple递归继承 */
// 前向声明
template <typename... Types>
class Tuple;

// 递归出口
template <>
class Tuple<> {};

// public继承: is-a关系
// private继承: 基于...实现
template <typename Head, typename... Tail>
class Tuple<Head, Tail...> : private Tuple<Tail...> {
    typedef Tuple<Tail...> inherited;
public:
    Tuple() {}
    Tuple(const Head& h, const Tail&... t)
        : m_head(h), inherited(t...) {}
    Head head() { return m_head; }
    // 子类自动转化为父类
    inherited& tail() { return *this; }
protected:
    Head m_head;
};

/* 例七: 递归复合 */
template<tyname... Values> 
class tup;

// 递归出口
template<>
class tup<> {};

template<typename Head, typename... Tail>
class tup<Head, Tail...> {
    typedef tup<Tail...> composited;
public:
    tup(const Head& h, const Tail&... t)
        : m_head(h), m_tail(t...) {}
    Head head() { return m_head; }
    // 传引用, 链式调用
    composited& tail() { return m_tail; }
protected:
    Head m_head;
    composited m_tail;
};


/* 非递归解包 */ 
template <typename T>
void display(T t) {
    std::cout << t << std::endl;
}

template <typename... args>
void vir_fun(args... argv)
{
    // 逗号表达式+初始化列表
	// (exp1, exp2) 执行exp1, exp2后返回exp2的值
	// 参数包可以在initialization list中解开

    //int arr[] = { (dispaly(argv),0)... };
	
	// c++17, fold expression
	// 展开为(display(arg1), ..., display(arg-1));
	(display(argv), ...);
}

int main() {
    // printX(1,2,3,"asa");
	printF("Hello % %!", 42, "World");
	//vir_fun(1, "http://www.biancheng.net", 2.34);
    std::cout << maximum(1,2,3,4) << std::endl;
}
