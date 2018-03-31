#include <Windows.h>
#include <Synchapi.h>
#include <iostream>
#include <time.h>
#include "Header.h"

int main()
{
	std::cout << "How many numbers to generate per attempt?" << std::endl;
	std::cin >> quantNums;
	unsigned int rng1;
	std::cout << "Specify maximum number to randomly generate." << std::endl;
	std::cin >> rng1;
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<unsigned int> vec(quantNums);
	unsigned int sleeptime = 0;
	for (auto &a : vec)
	{
		a = rand() % (rng1 + 1);
		std::cout << a << ' ';
	}
	std::cout << std::endl;
	long long attempts = 0;
	while (!allElemSame(vec))
	{
		if (attempts % 100000 == 0 && attempts != 0)
		{
			std::cout << "Currently at " << attempts << "th attempt." << std::endl;
			Sleep(3000);
		}
		++attempts;
		for (auto &a : vec)
		{
			a = rand() % (rng1 + 1);
			std::cout << a << ' ';
			for (unsigned int iter = retDig(rng1) - retDig(a); iter > 0; --iter)
			{
				std::cout << ' ';
			}
			Sleep(sleeptime);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "Found " << quantNums << " equal numbers after " << attempts << " attemps! Pheww..." << std::endl;
	system("pause");
}

template <class vecType>
bool allElemSame(std::vector<vecType> vec)
{
	if (vec.size() == 0)
	{
		std::cerr << "Empty Vector!" << std::endl;
		system("pause");
		throw;
	}
	unsigned int firstElem = vec[0];
	for (vecType &a : vec)
	{
		if (a != firstElem) return false;
	}
	return true;
}

unsigned int retDig(unsigned int ent)
{
	unsigned int digCount = 0;
	if (ent == 0) return 1;
	while (ent != 0)
	{
		ent /= 10;
		++digCount;
	}
	return digCount;
}