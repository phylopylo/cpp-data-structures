#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <memory>

#include "philip/u_ptr.hpp"
#include "philip/tree.hpp"
#include "philip/s_ptr.hpp"


int main() {
	// unique pointer from scratch
	// unique_pointer_demo();
	
	// shared pointer from scratch
	// shared_pointer_demo();

	// BFS/DFS Traversal and Binary Tree Construction
	tree_demo();
	
	return 0;
}
