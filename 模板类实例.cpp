//模板函数定义
#include <iostream>
using namespace std;
template <typename T>
T Max(T a, T b) {
		return (a > b) ? a : b;
}
//模板类定义
template <typename T, typename X, typename Y>
struct A {
	T foo(X&a);
	Y *c;
};

// 为模板类A添加foo成员函数的定义
template <typename T, typename X, typename Y>
T A<T, X, Y>::foo(X& a) {
    // 示例实现：假设T可以从X转换
    return static_cast<T>(a);
}

//修改const

int main() {
		int x = 10, y = 20;
		double m = 5.5, n = 3.3;
		cout << "Max of " << x << " and " << y << " is " << Max(x, y) << endl;
		cout << "Max of " << m << " and " << n << " is " << Max(m, n) << endl;
		return 0;
}