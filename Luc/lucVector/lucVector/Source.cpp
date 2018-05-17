#include <iostream>

class Vector {
	int m_size = 8;
	int m_iter = 0;
public:
	int* arr = new int[m_size];
	void M_PushBack(int p_input){
		if (m_iter < m_size) {
			arr[m_iter] = p_input;
			m_iter++;
		}
		else {
			M_CreateNewArr();
			arr[m_iter] = p_input;
			m_iter++;
			std::cout << "NewArr" << std::endl;
		}
	}
	void M_CreateNewArr(){
		m_size *= 2;
		int* temp = new int[m_size];
		for (int index = 0; index < m_size / 2; index++) {
			temp[index] = arr[index];
		}
		delete[]arr;
		arr = temp;
	}
};

int main() {
	Vector myVec;
	int toWhere = 100;
	for (int index = 0; index < toWhere+1; index++)myVec.M_PushBack(index);
	for (int index = 0; index < toWhere+1; index++) {
		std::cout << myVec.arr[index] << std::endl;
	}
	system("pause");
}