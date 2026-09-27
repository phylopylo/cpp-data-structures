#include "tree.hpp"

template <typename T>
class u_ptr {
	T* data;

public:
	explicit u_ptr(T* data) : data(data) { printf("Constructing u_ptr data %d\n", data); }

	// Getter
	T* get() {
		return data;
	};

	// Rule of Three:
	// If you define a destructor, a copy assignment operator, or a copy constructor, you need to define the other two. This is because using one implies that you are managing the lifetime of a resource, and to properly manage this lifetime you need to be able to handle these cases.

	// Destructor
	~u_ptr() {
		delete data;
	};

	// Copy Constructor
	u_ptr(const u_ptr& other) = delete;

	// Copy Assignment Operator
	u_ptr& operator=(const u_ptr& other) = delete;

	T& operator*() { return *data; };
	T* operator->() { return data; };
};

void unique_pointer_demo() {
	int x = 5; // stack allocated
	int* ptr;
	{
		u_ptr<int> int_ptr = (u_ptr<int>) new int;
		*int_ptr = x;
		printf("address of u_ptr: %p, data in u_ptr: %d", int_ptr.get(), *int_ptr);

		ptr = int_ptr.get();
	}
	// Throws ASAN error: heap-use-after-free
	// printf("testing if data is still in memory: %d", *ptr);

}

int main() {
	// BFS/DFS Traversal and Binary Tree Construction
	// tree_demo();
	
	// Unique Pointer Demo
	unique_pointer_demo();
	return 0;
}
