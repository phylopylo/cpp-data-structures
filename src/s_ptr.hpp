
template <typename T>
class s_ptr {
	T* data;
	uint32_t* references;

public:
	
	explicit s_ptr(T* data) : data(data), references(new int(1)) {};
	explicit s_ptr(const s_ptr& other) : data(other.data), references(other.references) {references++;};
	s_ptr& operator=(const s_ptr& other) {
		data = other.data;
		references = other.references;
		references++;
	};

	T* get() { return data; };
	T& operator*() { return *data; };
	T* operator->() { return data; };

	~s_ptr() {
		references--;
		if(!references){
			delete data;
			delete references;
		};
	};
};

void shared_pointer_demo() {
	printf("shared pointer demo!!!");
};
