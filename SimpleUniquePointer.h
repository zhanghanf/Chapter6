#pragma once
// A simple implementation of a unique pointer in C++简单的C++唯一指针实现
template <typename T>
class SimpleUniquePointer
{
	SimpleUniquePointer() = default;// Default constructor默认构造函数
	SimpleUniquePointer(const SimpleUniquePointer&) = delete; // Disable copy constructor禁用拷贝构造函数
	SimpleUniquePointer(T* ptr) : m_ptr(ptr) {} // Constructor with raw pointer使用原始指针的构造函数
	~SimpleUniquePointer() { if(m_ptr)delete m_ptr; } // Destructor析构函数
	SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete; // Disable copy assignment禁用拷贝赋值
	SimpleUniquePointer(SimpleUniquePointer&& other) noexcept // Move constructor移动构造函数
		: m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr; // Nullify the other pointer将另一个指针设为nullptr
	}
	SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept // Move assignment移动赋值
	{
		if (this != &other)
		{
			if (m_ptr) delete m_ptr; // Delete current resource删除当前资源
			m_ptr = other.m_ptr; // Transfer ownership转移所有权
			other.m_ptr = nullptr; // Nullify the other pointer将另一个指针设为nullptr
		}
		return *this;
	}
	T*get() const { return m_ptr; } // Get the raw pointer获取原始指针
private:
	T* m_ptr = nullptr; // Raw pointer原始指针
};

//使用delete删除构造函数和赋值运算符，防止拷贝操作，但刻意通过移动语义实现所有权转移，从而确保资源的唯一所有权。