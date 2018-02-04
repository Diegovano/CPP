#include <iostream>

using namespace std;

int main() {
	int input;
	cout << "Please enter the number you wish to factorise." << endl;
	cin >> input;
	int result = input;
	while (input > 1) {
		result = result*(input - 1);
		input = input - 1;
	}
	cout << result << endl;
}