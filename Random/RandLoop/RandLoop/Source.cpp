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
	std::cout << "The odds of getting " << quantNums << " equal numbers is 1 in " << pow(rng1 + 1, quantNums - 1) << '.' << std::endl;
	float sleepSecs;
	std::cout << "How many seconds delay between attempts?" << std::endl;
	std::cin >> sleepSecs;
	unsigned int sleeptime = sleepSecs * 1000;
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<unsigned int> vec(quantNums);
	std::cout << std::endl;
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
		}
		std::cout << std::endl;
		Sleep(sleeptime);
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