#include "philip/s_ptr.hpp"

void shared_pointer_demo() {
	std::cout << "shared pointer demo!!!" << std::endl << std::endl;
	s_ptr<uint32_t> epic_pointer = s_ptr<uint32_t>::make_s_ptr(5);
	s_ptr<uint32_t> copy_of_epic_pointer = epic_pointer;
};
