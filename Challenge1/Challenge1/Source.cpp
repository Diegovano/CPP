#include <iostream>

int pwr(int base, int exponent) {
	int origbase = base;
	if (exponent == 0)return 1;
	else if (exponent == 1)return base;
	else {
		for (; exponent > 1; exponent--) {
			base = origbase*base;
		}
	}
	return base;
}

int sqrRt(int input) {
	for (int i = 1; i < 10000; i++) {
		if (input%i == 0 && pwr(i, 2) == input)return i;
		else;
	}
}

int main() {
	int l1;
	int l2;
	std::cout << "Give the lengths of the opposite and the adjecents.\n";
	std::cin >> l1;
	std::cin >> l2;
	int l3 = pwr(l1, 2) + pwr(l2, 2);
	std::cout << sqrRt(l3) << std::endl;
	system("pause");
}