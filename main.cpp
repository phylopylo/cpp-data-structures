#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <memory>

class Node {
public:
	Node(int value) : value(value) {}

	int value;
	std::shared_ptr<Node> left{nullptr};
	std::shared_ptr<Node> right{nullptr};
};

std::shared_ptr<Node> exampleTree() {

	// Use Nodes to construct an example tree
	std::shared_ptr<Node> root = std::make_shared<Node>(3);
	root->left = std::make_shared<Node>(8);
	root->right = std::make_shared<Node>(4);
	root->left->left = std::make_shared<Node>(6);
	root->left->right = std::make_shared<Node>(4);
	root->right->left = std::make_shared<Node>(7);
	root->right->right = std::make_shared<Node>(2);
	return root;
};

void printTreeBFS(std::shared_ptr<Node>& node) {
	std::vector<std::shared_ptr<Node>> queue;
	queue.push_back(node);

	std::string output;
	unsigned int i(0);
	while(i < queue.size()) {

		std::shared_ptr<Node> cur = queue[i];
		output += std::format("{} ", cur->value);

		std::shared_ptr<Node> L = cur->left; // Left Child 
		if(L != nullptr) {
			queue.push_back(L);
		}

		std::shared_ptr<Node> R = cur->right; // Right Child
		if(R != nullptr) {
			queue.push_back(R);
		}
		i++;
	}
	std::cout << output << std::endl;
}

void printTreeDFS_recursive(std::shared_ptr<Node>& node) {
	// Recursive Solution.
	std::cout << node->value << ' ';
	if(node->left)
		printTreeDFS_recursive(node->left);
	if(node->right)
		printTreeDFS_recursive(node->right);
}

void printTreeDFS_iterative(std::shared_ptr<Node>& node) {
	// Iterative Solution.
	std::vector<std::shared_ptr<Node>> stack;
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

std::shared_ptr<Node> build(std::vector<std::shared_ptr<Node>>& array, int start, int end) {
	if(start >= end) return nullptr;
	int midpoint = start + (end - start) / 2;
	std::shared_ptr<Node> root = array[midpoint];
	root->left = build(array, start, midpoint);
	root->right = build(array, midpoint + 1, end);
	return root;
}

std::shared_ptr<Node> rebuildBalancedTree(std::shared_ptr<Node>& node) {

	// First, construct a queue of Nodes.
	std::vector<std::shared_ptr<Node>> array;
	array.push_back(node);

	unsigned int i = 0;
	while(i < array.size()) {

		std::shared_ptr<Node> cur = array[i];

		std::shared_ptr<Node> L = cur->left; // Left Child 
		if(L != nullptr) {
			array.push_back(L);
		}

		std::shared_ptr<Node> R = cur->right; // Right Child
		if(R != nullptr) {
			array.push_back(R);
		}
		i++;
	}
	
	// Sort the vector
	std::sort(array.begin(), array.end(),
	    [](const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
		return a->value < b->value;
	    });


	// Rebuild the Tree
	return build(array, 0, array.size());
}

int main() {
	std::shared_ptr<Node> tree = exampleTree();
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
	return 0;
}
