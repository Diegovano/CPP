#include <iostream>

class Vector {
private:
	int iter = 0;
public:
	int size = 8;
	int* arr = new int[size];
	void m_PushBack(int entrd) {
		if (iter < size) {
			arr[iter] = entrd;
		}
		else {
			size *= 2;
			int* temp = new int[size];
			for (int index2 = 0u; index2 < size / 2; index2++) {
				temp[index2] = arr[index2];
			}
			delete[] arr;
			arr = temp;
			arr[iter] = entrd;
		}
		iter++;
	}
	void m_PrintVec() {
		for (int index2 = 0u; index2 < iter; index2++) {
			std::cout << arr[index2] << std::endl;
		}
	}
	int m_vecSize() {
		return iter;
	}
};

struct basicLogic {
	int _AND(unsigned int num1, unsigned int num2) {
		return num1 & num2;
	}
	int _OR(unsigned int num1, unsigned int num2) {
		return num1 | num2;
	}
	int _NOT(unsigned int num1) {
		return ~num1;
	}
	int _NAND(unsigned int num1, unsigned int num2) {
		return ~(num1 & num2);
	}
	int _NOR(unsigned int num1, unsigned int num2) {
		return ~(num1 | num2);
	}
	int _XOR(unsigned int num1, unsigned int num2) {
		return num1^num2;
	}
	int _XNOR(unsigned int num1, unsigned int num2) {
		return ~(num1^num2);
	}

};

Vector add(Vector num1, Vector num2) {
	Vector res;
	res.m_PushBack(num1.arr[0] ^ num2.arr[0]); //sum      //addition of first binary digits
	int carry = num1.arr[0] & num2.arr[0];  //carry
	for (int iter = 0; iter < num1.m_vecSize() || iter < num2.m_vecSize(); iter++) {
		res.m_PushBack(carry ^ (num1.arr[iter + 1] ^ num2.arr[iter + 1]));
		carry = (num1.arr[iter + 1] & num2.arr[iter + 1]) | (carry&(num1.arr[iter + 1] ^ num2.arr[iter + 1]));
	}
	return res;
}

int substract(int* num1Arr, int* num2Arr);

int main() {
	Vector firstNum;
	Vector secondNum;
	int num1, num2, result = 0;
	std::cin >> num1 >> num2;
	for (int iter = 0u; iter < 16; iter++) {
		firstNum.m_PushBack((num1 & (1 << iter)) >> iter);
		secondNum.m_PushBack((num2 & (1 << iter)) >> iter);
	}
	//  std::cout << add(firstNum, secondNum).arr[0];
	for (int index = 0u; index < 16; index++) {
		int debug = add(firstNum, secondNum).arr[index];
		result += ((add(firstNum, secondNum).arr[index] & 1) << index);
		//      std::cout << result;
	}
	std::cout << result << std::endl;
	//  basicLogic log;
	//  std::cout << log._AND(num1, num2) << std::endl << log._NAND(num1, num2) << std::endl << log._NOR(num1, num2) << std::endl << log._NOT(num1) << " " << log._NOT(num2) << std::endl;
	//  std::cout << log._OR(num1, num2) << std::endl << log._XNOR(num1, num2) << std::endl << log._XOR(num1, num2) << std::endl;
	//  for (int i = 0; i < 100; i++) {
	//      myVec.m_PushBack(i);
	//  }
	//  myVec.m_PrintVec();
	//  and, nand, nor, not, or, xnor, xor
	//  std::cout << !num1;
	system("pause");
	return 0;
}