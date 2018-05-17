#include <iostream>
#include <string>

int factorial(int val) {
	if (val > 1) 
		return factorial(val - 1) * val;
	return 1; 
}

int main() {
	int val;
	std::cin >> val;
	std::cout << factorial(val) << std::endl;
	system("pause");
}