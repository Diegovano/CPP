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
		for (int index2 = 0; index2 < iter; index2++) {
			std::cout << arr[index2] << std::endl;
		}
	}
	void m_clearVec() {
		iter = 0; size = 8;
	}
	int m_vecSize() {
		return iter;
	}
};

class Adder {
private:
	static const int numBits = 16;
protected:
public:
	static int firstNum, secondNum;
	static Vector num1arr, num2arr;

	static void M_IntToBitArr(int num1, int num2) {
		num1arr.m_clearVec(); num2arr.m_clearVec();
		for (int index = 0; index < numBits; index++) {
			num1arr.m_PushBack((num1&(1 << index)) >> index);
			num2arr.m_PushBack((num2&(1 << index)) >> index);
		}
		//		num1arr.m_PrintVec();
		//		num2arr.m_PrintVec();
	}

	static int M_BitArrToInt(Vector toChg) {
		int res = 0;
		for (int index = 0; index < numBits; index++) {
			if ((res&(1 << index)) >> index == toChg.arr[index]);
			else {
				res |= (toChg.arr[index] << index);
			}
		}
		return res;
	}

	static int M_Add(int num1, int num2) {
		Vector resArr;
		M_IntToBitArr(num1, num2);
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

Vector Adder::num1arr; Vector Adder::num2arr;

int main() {
	int num1 = 1, num2 = 1;
	do {
		std::cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0) break;
		std::cout << Adder::M_Add(num1, num2) << "\n\n";
	}
	while (num1 != 0 && num2 != 0);
	system("pause");
	return  0;
}