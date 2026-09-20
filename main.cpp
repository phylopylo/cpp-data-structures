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
	return root;
};

void printTreeBFS(std::shared_ptr<Node> node) {
	std::vector<std::shared_ptr<Node>> queue{node};
	std::string output;
	unsigned int i(0);
	while(i < queue.size()) {

		Node* cur = queue[i];
		output += std::format("{}\n", cur->value);


		std::unique_ptr<Node> L = cur->left; // Left Child 
		if(L != nullptr) {
			queue.push_back(L);
		}

		std::unique_ptr<Node> R = cur->right; // Right Child
		if(R != nullptr) {
			queue.push_back(R);
		}
		i++;
	}
	std::cout << output;
}

int main() {
	std::unique_ptr<Node> tree = exampleTree();
	std::cout << "Printing BFS Search of Example Tree!" << std::endl << std::endl;
	printTreeBFS(tree);
	return 0;
}
