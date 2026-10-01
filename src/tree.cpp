#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <memory>

#include <philip/s_ptr.hpp>

class Node {
public:
	Node(int value) : value(value) {}

	int value;
	s_ptr<Node> left{nullptr};
	s_ptr<Node> right{nullptr};
};

s_ptr<Node> exampleTree() {

	// Use Nodes to construct an example tree
	s_ptr<Node> root = s_ptr<Node>::make_s_ptr(3);
	root->left = s_ptr<Node>::make_s_ptr(8);
	root->right = s_ptr<Node>::make_s_ptr(4);
	root->left->left = s_ptr<Node>::make_s_ptr(6);
	root->left->right = s_ptr<Node>::make_s_ptr(4);
	root->right->left = s_ptr<Node>::make_s_ptr(7);
	root->right->right = s_ptr<Node>::make_s_ptr(2);
	return root;
};

void printTreeBFS(s_ptr<Node>& node) {
	std::vector<s_ptr<Node>> queue;
	queue.push_back(node);

	std::string output;
	unsigned int i(0);
	while(i < queue.size()) {

		s_ptr<Node> cur = queue[i];
		output += std::format("{} ", cur->value);

		s_ptr<Node> L = cur->left; // Left Child 
		if(L != nullptr) {
			queue.push_back(L);
		}

		s_ptr<Node> R = cur->right; // Right Child
		if(R != nullptr) {
			queue.push_back(R);
		}
		i++;
	}
	std::cout << output << std::endl;
}

void printTreeDFS_recursive(s_ptr<Node>& node) {
	// Recursive Solution.
	std::cout << node->value << ' ';
	if(node->left)
		printTreeDFS_recursive(node->left);
	if(node->right)
		printTreeDFS_recursive(node->right);
}

void printTreeDFS_iterative(s_ptr<Node>& node) {
	// Iterative Solution.
	std::vector<s_ptr<Node>> stack;
	stack.push_back(node);
	while(!stack.empty()) {

		std::cout << node->value << ' ';
		
		if(node->right)
			stack.push_back(node->right);
		if(node->left)
			stack.push_back(node->left);

		node = stack.back(); stack.pop_back();
	}
}

s_ptr<Node> build(std::vector<s_ptr<Node>>& array, int start, int end) {
	if(start >= end) return nullptr;
	int midpoint = start + (end - start) / 2;
	s_ptr<Node> root = array[midpoint];
	root->left = build(array, start, midpoint);
	root->right = build(array, midpoint + 1, end);
	return root;
}

s_ptr<Node> rebuildBalancedTree(s_ptr<Node>& node) {

	// First, construct a queue of Nodes.
	std::vector<s_ptr<Node>> array;
	array.push_back(node);

	unsigned int i = 0;
	while(i < array.size()) {

		s_ptr<Node> cur = array[i];

		s_ptr<Node> L = cur->left; // Left Child 
		if(L != nullptr) {
			array.push_back(L);
		}

		s_ptr<Node> R = cur->right; // Right Child
		if(R != nullptr) {
			array.push_back(R);
		}
		i++;
	}
	
	// Sort the vector
	std::sort(array.begin(), array.end(),
	    [](s_ptr<Node>& a, s_ptr<Node>& b) {
		return a->value < b->value;
	    });


	// Rebuild the Tree
	return build(array, 0, array.size());
}

void tree_demo() {

	s_ptr<int> ptr = s_ptr<int>::make_s_ptr(5);

	s_ptr<Node> tree = exampleTree();
	std::cout << "Printing BFS Search of Example Tree!" << std::endl << std::endl;
	printTreeBFS(tree);
	std::cout << "Printing Recursive DFS Search of Example Tree!" << std::endl << std::endl;
	printTreeDFS_recursive(tree);
	std::cout << std::endl;
	std::cout << "Printing Iterative DFS Search of Example Tree!" << std::endl << std::endl;
	printTreeDFS_iterative(tree);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Rebalancing tree by traversing, sorting, and recreating." << std::endl << std::endl;
	tree = rebuildBalancedTree(tree);
	std::cout << "Printing BFS Search of Example Tree!" << std::endl << std::endl;
	printTreeBFS(tree);
}
