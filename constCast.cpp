//类型转换函数
#include <iostream>
using namespace std;
//
void carbon(const int& p) {
	//p++; //错误，不能修改const对象
	auto& q = const_cast<int&>(p); //去掉const属性
	q++; //修改成功
}
//也可以使用隐式转换、从对象中去除volatile属性

//static_cast可以反转定义良好的隐式转换：
short intToShort(void* i) {
	return *static_cast<short*>(i);
}
//reinterpret_cast可以在任何两个指针类型之间转换：但程序员需要控制转换正确性
void pointerCast() {
	int a = 10;
	void* p = &a;
	int* ip = reinterpret_cast<int*>(p);
	cout << *ip << endl;
}

//narrow_cast：从较大类型转换为较小类型，可能会丢失信息:执行时进行窄化检查
template <typename Target, typename Source>
Target narrow_cast(Source value) {
	Target temp = static_cast<Target>(value);
	if (static_cast<Source>(temp) != value) {
		throw runtime_error("narrow_cast: 失去信息");
	}
	return temp;
}
int main() {
	const int a = 10;
	cout << "a before carbon: " << a << endl;
	carbon(a);
	cout << "a after carbon: " << a << endl;
	pointerCast();
	try {
		int big = 300;
		short small = narrow_cast<short>(big);
		cout << "narrow_cast succeeded: " << small << endl;
		big = 70000; // 超出short范围
		small = narrow_cast<short>(big); // 抛出异常
		cout << "narrow_cast succeeded: " << small << endl;
	} catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
	return 0;
}