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

std::shared_ptr<Node> exampleTree();
void printTreeBFS(std::shared_ptr<Node>& node);
void printTreeDFS_recursive(std::shared_ptr<Node>& node);
void printTreeDFS_iterative(std::shared_ptr<Node>& node);
std::shared_ptr<Node> build(std::vector<std::shared_ptr<Node>>& array, int start, int end);
std::shared_ptr<Node> rebuildBalancedTree(std::shared_ptr<Node>& node);
void tree_demo();
