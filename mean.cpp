#include<cstdio>
#include<stddef>
//该函数使用传入的数组和其大小来计算数组元素的平均值
long mean(const long* arr, size_t size) {
	if (size == 0) return 0; // Handle empty array case
	long sum = 0;
	for (size_t i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}
