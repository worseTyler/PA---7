#include "Binary Tree.h"
#include <queue>
int main(void) {
	BinaryTree<char, std::string> test("MorseCode.txt");
	std::ifstream convert("Convert.txt");
	std::string temp;
	std::queue<std::string> hold;
	while (convert.good()) {
		getline(convert, temp);
		test.convert(temp);
		std::cout << '\n';
	}

	return 0;
}