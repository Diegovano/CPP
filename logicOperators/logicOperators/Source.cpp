
#include "vectorClass.h"

int bitArrToInt(Vector toChg) {
	int res = 0;
	for (int index = 0; index < sizeof(int) ; index++) {
		if ((res&(1 << index)) >> index == toChg.arr[index]);
		else {
			res |= (toChg.arr[index] << index);
		}
	}
	return res;
}

int add(int num1, int num2) {
	Vector res, firstNum, secondNum;
	for (int iter = 0; iter < sizeof(int); iter++) {
		firstNum.m_PushBack((num1 & (1 << iter)) >> iter);
		secondNum.m_PushBack((num2 & (1 << iter)) >> iter);
	}
	res.m_PushBack(firstNum.arr[0]^secondNum.arr[0]); //sum		//addition of first binary digits
	int carry = firstNum.arr[0] & secondNum.arr[0];  //carry
	for (int iter = 0; iter < firstNum.m_vecSize() || iter < secondNum.m_vecSize(); iter++) {
		res.m_PushBack(carry ^ (firstNum.arr[iter + 1] ^ secondNum.arr[iter + 1]));
		carry = (firstNum.arr[iter + 1] & secondNum.arr[iter + 1]) | (carry&(firstNum.arr[iter + 1] ^ secondNum.arr[iter + 1]));
	}
	return bitArrToInt(res);
}

int substract(int* num1Arr, int* num2Arr);

int main() {
	int num1, num2 = 0;
	std::cin >> num1 >> num2;
	std::cout << add(num1, num2) << std::endl;
	system("pause");
	return 0;
}