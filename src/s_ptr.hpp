
template <typename T>
class s_ptr {
	T* data;
	uint32_t* references;

public:
	
	explicit s_ptr(T* data) : data(data), references(new uint32_t(1)) {
		std::cout << "s_ptr constructor called! refcount is " << *references << std::endl;
	};
	s_ptr(const s_ptr& other) : data(other.data), references(other.references) {
		(*references)++;
		std::cout << "s_ptr copy constructor called! refcount is " << *references << std::endl;
	};

	s_ptr& operator=(const s_ptr& other) {
		data = other.data;
		references = other.references;
		(*references)++;
		std::cout << "Copy operator called! increased refcount to " << references << std::endl;
	};

	s_ptr(s_ptr&& other) noexcept {
		data = other.data;
		references = other.references;
		other.data = nullptr;
		other.references = nullptr;
	};

	s_ptr operator=(s_ptr&& other) noexcept {
		data = other.data;
		references = other.references;
		other.data = nullptr;
		other.references = nullptr;
	};

	T* get() { return data; };
	T& operator*() { return *data; };
	T* operator->() { return data; };

	~s_ptr() {
		(*references)--;
		std::cout << "Destructor called! decreased refcount to " << *references << std::endl;
		if(!*references){
			delete data;
			delete references;
			std::cout << "refcount hit zero!!! deleted mem allocation for data and refcount." << std::endl;
		};
	};
};

void shared_pointer_demo() {
	std::cout << "shared pointer demo!!!" << std::endl << std::endl;
	s_ptr<uint32_t> epic_pointer = s_ptr<uint32_t>(new uint32_t(5));
	s_ptr<uint32_t> copy_of_epic_pointer = epic_pointer;
};
