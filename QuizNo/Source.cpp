#include <iostream>
#include <string>

class quiz{
public:
	unsigned long quizNum = 0;
	void M_ChgQStat(int id, bool pass) {
		if (pass) {
			quizNum |= (1 << (id - 1));
		}
		else {
			quizNum &= ~(1 << (id - 1));
		}
	}
	std::string M_ReturnQStat(int id) {
		return ((quizNum & (1 << (id - 1))) >> (id - 1)) ? "Passed" : "Failed";
	}
};

void printRes(unsigned long quiz) {
	for (int iter = 0; quiz != 0 && iter < 31; ++iter) {
		if (((quiz & (1 << iter)) >> iter) == 1) {
			std::cout << "Student " << iter + 1 << " Has Passed The Quiz.\n";
			quiz &= ~(1 << iter);
		}
		else {
			std::cout << "Student " << iter + 1 << " Has Failed The Quiz.\n";
		}
//		std::cout << quiz << std::endl;
	}
}

int main() {
	quiz q1;
//	std::cout << q1.quizNum << std::endl;
	unsigned int studId = 0;
	while (studId < 31) {
		std::cout << "Enter Student ID: ";
		std::cin >> studId;
		if (studId > 30) break;
		int sel;
		std::cin >> sel;
		if (sel == 1) {
			bool pass;
			std::cout << "0 for fail; 1 for pass.\n";
			std::cin >> pass;
			q1.M_ChgQStat(studId, pass);
		}
		else {
			std::cout << "Student " << studId << " has " << q1.M_ReturnQStat(studId) << std::endl;
		}
		std::cout << "The 'Value' of Your Quiz is : " << q1.quizNum << std::endl;
	}
	unsigned long tempQuizNo;
	std::cout << "Enter the Quiz Number: ";
	std::cin >> tempQuizNo;
	std::cout << std::endl;
	printRes(tempQuizNo);
	system("pause");
	return 0;
}