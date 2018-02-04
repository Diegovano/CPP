#include <iostream>

namespace luc {
	double& sqrt(double &input) {
		double num_mod = 1;
		double answer = 1;
		size_t times_executed_decimal = 0;
		while (answer * answer != input) {
			if (answer * answer < input) { 
				if (num_mod != 1) { 
					num_mod /= 2; 
					times_executed_decimal++;
				}
				answer += num_mod;
			}
			else if (answer * answer > input) {
				num_mod /= 2;
				answer -= num_mod;
				times_executed_decimal++;
			}
			if (times_executed_decimal > 16) break;
		}
		return answer;
	}
}

int main() {
	double myNum = 53.2;
	std::cout << "what number would you like to square root : ";
	std::cin >> myNum;
	std::cout << "answer : " << luc::sqrt(myNum) << std::endl;
	std::cout << "answer of standard : " << std::sqrt(myNum) << std::endl;

	system("pause");
}