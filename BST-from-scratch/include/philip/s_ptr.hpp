#pragma once

#include <ostream>
#include <iostream>


template <typename T>
class s_ptr {
	T* data;
	uint32_t* references;

public:
	
	//explicit s_ptr(T* data) : data(data), references(new uint32_t(1)) {
	//	std::cout << "s_ptr constructor called! refcount is " << *references << std::endl;
	//};

	s_ptr(T* data) : data(data), references(new uint32_t(1)) {
		std::cout << "s_ptr constructor called! refcount is " << *references << std::endl;
	};

	explicit s_ptr(T data) : data(data), references(new uint32_t(1)) {
		std::cout << "s_ptr constructor called! refcount is " << *references << std::endl;
	};

	s_ptr(const s_ptr& other) : data(other.data), references(other.references) {
		(*references)++;
		std::cout << "s_ptr copy constructor called! refcount is " << *references << std::endl;
	};

	s_ptr& operator=(const s_ptr& other) {
		if (references){
			(*references)--;
			if ((*references) == 0) {
				delete data;
				delete references;
			};
		}
		data = other.data;
		references = other.references;
		(*references)++;
		std::cout << "Copy operator called! increased refcount to " << references << std::endl;
		return *this;
	};

	s_ptr(s_ptr&& other) noexcept {
		data = other.data;
		references = other.references;
		other.data = nullptr;
		other.references = nullptr;
	};

	s_ptr& operator=(s_ptr&& other) noexcept {
		if (references){
			(*references)--;
			if ((*references) == 0) {
				delete data;
				delete references;
			};
		}
		data = other.data;
		references = other.references;
		other.data = nullptr;
		other.references = nullptr;
		return *this;
	};

	static s_ptr make_s_ptr(T data) {
		s_ptr ptr = (s_ptr<T>) new T(data);
		return ptr;
	};

	T* get() { return data; };
	T& operator*() { return *data; };
	T* operator->() { return data; };

	bool operator==(const auto& other) const {
		return other == *data;
	};

	bool operator!=(const auto& other) const {
		return other != data;
	};

	operator bool() const {
		return data != nullptr;
	};

	~s_ptr() {
		if (!references) return;
		(*references)--;
		std::cout << "Destructor called! decreased refcount to " << *references << std::endl;
		if(*references == 0){
			delete data;
			delete references;
			std::cout << "refcount hit zero!!! deleted mem allocation for data and refcount." << std::endl;
		};
	};
};

void shared_pointer_demo();
