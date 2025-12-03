#include <iostream>

// 递归解包
void printX() {
    std::cout << std::endl;
}

template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
    std::cout << firstArg << std::endl;
    std::cout << "left: " << sizeof...(args) << " params" << " ";
    // args 会被分为2部分 一部分是第一个参数 第二部分是args...
    printX(args...);
}


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

int maximum(int n) {return n;}

template<typename...Args>
int maximum(int n, Args... args) {
    return std::max(n, maximum(args...));
}

// 非递归解包
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
