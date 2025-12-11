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

template<typename T>
long mean_template(const T* arr, size_t size) {
	if (size == 0) return 0; // Handle empty array case
	long sum = 0;
	for (size_t i = 0; i < size; ++i) {
		sum += static_cast<long>(arr[i]);
	}
	return sum / size;
}

//测试
int main() {
	long arr1[] = {1, 2, 3, 4, 5};
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("Mean of arr1: %ld\n", mean(arr1, size1));
	int arr2[] = {10, 20, 30, 40, 50};
	size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("Mean of arr2: %ld\n", mean_template(arr2, size2));
	double arr3[] = {1.5, 2.5, 3.5};
	size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
	printf("Mean of arr3: %ld\n", mean_template(arr3, size3));
	return 0;
}