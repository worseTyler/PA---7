#ifndef BinaryTree_H
#define BinaryTree_H

#include "BinaryMorseCode.h"
#include "TreeNode.h"

template <class T, class M>
class BinaryTree {
private:
	TreeNode<T, M>* root;

	void insert(TreeNode<T, M>*&, TreeNode<T, M>*&);
	void display_in_order(TreeNode<T, M>*) const;
	void display_pre_order(TreeNode<T, M>*) const;
	void display_post_order(TreeNode<T, M>*) const;
	void destroy_subtree(TreeNode<T, M>*&);
public:
	BinaryTree() {
		root = nullptr;
	}
	BinaryTree(std::string file_name);
	~BinaryTree();
	void insert_node(T, M);
	void display_in_order();
	void display_pre_order();
	void display_post_order();
	M search(T);
	void convert(std::string);

};

template <class T, class M>
BinaryTree<T, M>::BinaryTree(std::string file_name) {
	root = nullptr;
	std::ifstream convert(file_name);
	TreeNode<char, std::string> temp;
	while (convert) {
		convert >> temp;
		insert_node(temp.letter, temp.morse);
	}
	convert.close();
}

template <class T, class M>
void BinaryTree<T, M>::insert_node(T letter, M morse) {
	TreeNode<T, M>* newNode = new TreeNode<T, M>;
	newNode->letter = letter;
	newNode->morse = morse;

	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}

template <class T, class M>
BinaryTree<T,M>::~BinaryTree() {
	destroy_subtree(root);
}

template <class T, class M>
void BinaryTree<T, M>::insert(TreeNode<T, M>*& nodePtr, TreeNode<T, M>*& newNode) {
	if (nodePtr == nullptr)
		nodePtr = newNode;
	else if (nodePtr->letter > newNode->letter)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

template <class T, class M>
void BinaryTree<T, M>::display_in_order() {
	display_in_order(root);
}

template <class T, class M>
void BinaryTree<T, M>::display_in_order(TreeNode<T, M>* nodePtr) const {
	if (nodePtr) {
		display_in_order(nodePtr->left);
		std::cout << nodePtr->letter << " " << nodePtr->morse << std::endl;
		display_in_order(nodePtr->right);
	}
}

template <class T, class M>
void BinaryTree<T, M>::display_pre_order() {
	display_pre_order(root);
}

template <class T, class M>
void BinaryTree<T, M>::display_pre_order(TreeNode<T, M>* nodePtr) const {
	if (nodePtr) {
		std::cout << nodePtr->letter << " " << nodePtr->morse << std::endl;
		display_pre_order(nodePtr->left);
		display_pre_order(nodePtr->right);
	}
}

template <class T, class M>
void BinaryTree<T, M>::display_post_order() {
	display_post_order(root);
}

template <class T, class M>
void BinaryTree<T, M>::display_post_order(TreeNode<T, M>* nodePtr) const {
	if (nodePtr) {
		display_post_order(nodePtr->left);
		display_post_order(nodePtr->right);
		std::cout << nodePtr->letter << " " << nodePtr->morse << std::endl;
	}
}

template <class T, class M>
M BinaryTree<T, M>::search(T data) {
	TreeNode<T, M>* sNode = root;
	while (sNode) {
		if (sNode->letter == data) {
			return sNode->morse;
		}
		else if (sNode->letter < data) {
			sNode = sNode->right;
		}
		else {
			sNode = sNode->left;
		}
	}
	return M();
}

template <class T, class M>
void BinaryTree<T, M>::convert(std::string input) {
	for (unsigned int index = 0; index < input.length(); index++) {
		if (input[index] >= 'a' && input[index] <= 'z')
			input[index] = (char)toupper(input.at(index));
		if (input[index] == (char)32)
			std::cout << "   ";
		else
			std::cout << search(input.at(index)) << " ";
	}
}


template <class T, class M>
void BinaryTree<T, M>::destroy_subtree(TreeNode<T, M>*& NodePtr) {
	if (NodePtr) {
		if (NodePtr->left)
			destroy_subtree(NodePtr->left);
		if (NodePtr->right)
			destroy_subtree(NodePtr->right);
		delete NodePtr;
	}
}


#endif

