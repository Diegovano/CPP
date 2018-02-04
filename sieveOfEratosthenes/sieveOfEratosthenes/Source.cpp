//Diego's Program
 #include <iostream>
#include <chrono>

int primifier(int size) {
	const int index = size;
	int * result = new int[index];
	for (int prg = 2; prg <= size; prg++) {
		bool overIndex = false;
		if (result[prg] == 999) {}
		else {
			std::cout << prg << std::endl;
			int prevSum = prg;
			while (overIndex == false) {
				if (prevSum + prg > size) {
					overIndex = true;
				}
				else {
					result[prevSum + prg] = 999;
					prevSum = prevSum + prg;\
				}
			}
		}
	}
	return 0;
} 

/*int main() {
	int input;
	std::cout << "Up to which number do you want look for primes?\n";
	std::cin >> input;
	primifier(input);
	system("pause");
}*/

//Luc's Program
//#include <iostream>

 void GetArrayOfPrimes(size_t sze) {
	size_t size = sze + 1;
	bool* arrayIsPrime = new bool[size];

	for (size_t index = 0; index < size; index++)
		arrayIsPrime[index] = true;
	size_t index = 2;
WHILE:while (arrayIsPrime[index]) {
	std::cout << index << std::endl;
	for (size_t indexOfArr = index*2; indexOfArr < size; indexOfArr += index)
		arrayIsPrime[indexOfArr] = false;
	index++;
}
	  index++;
	  if (index < size) goto WHILE;
}

int main() {
	std::chrono::high_resolution_clock::time_point n = std::chrono::high_resolution_clock::now();
	GetArrayOfPrimes(1000000);
	std::chrono::high_resolution_clock::duration d = std::chrono::high_resolution_clock::now() - n;
	double dduration = d.count(); 
	std::chrono::high_resolution_clock::time_point n2 = std::chrono::high_resolution_clock::now();
	primifier(1000000);
	std::chrono::high_resolution_clock::duration d2 = std::chrono::high_resolution_clock::now() - n;
	double dduration2 = d2.count();
	std::cout << dduration/1000 << ' ' << dduration2/1000 << std::endl;
	std::cout << dduration2 / dduration << std::endl;
	system("pause");
}