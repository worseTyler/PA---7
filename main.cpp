#include "Binary Tree.h"
#include <queue>
int main(void) {
	
	// Create binary tree
	BinaryTree<char, std::string> test("MorseCode.txt"); // I open and close MorseCode.txt in the constructor
	
	// Print tree in different orders
	std::cout << "Printing the tree in order: \n";
	test.display_in_order();
	std::cout << std::endl;
	std::cout << "Printing the tree in pre-order: \n";
	test.display_pre_order();
	std::cout << std::endl;
	std::cout << "Printing the tree in post-order: \n";
	test.display_post_order();
	std::cout << std::endl;
	system("pause");
	system("cls");

	// Convert text to morse code using Binary tree
	std::cout << "Converted to morse text: \n";
	std::ifstream convert("Convert.txt");
	std::string temp;
	while (convert.good()) {
		getline(convert, temp);
		test.convert(temp);
		std::cout << '\n';
	}
	convert.close();
	return 0;
}