#ifndef TreeNode_H
#define TreeNode_H

#include "BinaryMorseCode.h"


template <class T, class M>
class TreeNode {
public:
	T letter;
	M morse;

	TreeNode<T, M>* left;
	TreeNode<T, M>* right;

	TreeNode() {
		letter = T();
		morse = M();

		left = nullptr;
		right = nullptr;
	}

	friend std::istream &operator >>(std::istream& input, TreeNode<T, M>& node) {
		input >> node.letter;
		input >> node.morse;
		return input;
	}
};


#endif 
