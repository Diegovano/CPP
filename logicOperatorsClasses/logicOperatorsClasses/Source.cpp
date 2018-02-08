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
			for (int index2 = 0; index2 < size / 2; index2++) {
				temp[index2] = arr[index2];
			}
			delete[] arr;
			arr = temp;
			arr[iter] = entrd;
		}
		iter++;
	}
	void m_PrintVec() {
		for (int index2 = 0; index2 < iter; index2++) {
			std::cout << arr[index2] << std::endl;
		}
	}
	int m_vecSize() {
		return iter;
	}
};

class Adder {
private:
	int numBits;
protected:
public:
	int firstNum, secondNum;
	Vector num1arr, num2arr;
	Adder(int bitnum, int numtwo, int numone) {
		numBits = bitnum; secondNum = numtwo; firstNum = numone;
		for (int index = 0; index < numBits; index++) {
			num1arr.m_PushBack((firstNum&(1 << index)) >> index);
			num2arr.m_PushBack((secondNum&(1 << index)) >> index);
		}
	}
	int M_BitArrToInt(Vector toChg) {
		int res = 0;
		for (int index = 0; index < numBits; index++) {
			if ((res&(1 << index)) >> index == toChg.arr[index]);
			else {
				res |= (toChg.arr[index] << index);
			}
		}
		return res;
	}
	int M_Add() {
		Vector resArr;
		resArr.m_PushBack(num1arr.arr[0] ^ num2arr.arr[0]);
		int carry = num1arr.arr[0] & num2arr.arr[0];
		for (int iter = 1; iter <= numBits || iter <= numBits; iter++) {
			resArr.m_PushBack(carry ^ (num1arr.arr[iter] ^ num2arr.arr[iter]));
			carry = (num1arr.arr[iter] & num2arr.arr[iter]) | (carry&(num1arr.arr[iter] ^ num2arr.arr[iter]));
		}
//		resArr.m_PrintVec();
		return M_BitArrToInt(resArr);
	}
};

int main() {
	int num1, num2;
	std::cin >> num1 >> num2;
	Adder op1(16, num1, num2);
	std::cout << op1.M_Add() << std::endl;
	system("pause");
	return  0;
}