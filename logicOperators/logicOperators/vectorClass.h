#pragma once

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
