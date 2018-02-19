#include <iostream>
#include <string>

using namespace std;

struct swimmingPool
{
private:
	unsigned int length, width, depth;
	double pricePerM2;
public:
	swimmingPool(unsigned int z, unsigned int y, unsigned int x, double price)
	{
		length = z; width = y; depth = x; pricePerM2 = price;
	}
	void printDimentions()
	{
		cout << "Length: " << length << endl
			<< "Width: " << width << endl
			<< "Depth: " << depth << endl;
	}
	double printPriceOfLand()
	{
		return getVolume() * pricePerM2;
	}
	double getVolume()
	{
		return length * width * depth;
	}
	void operator+(unsigned int incrSize)
	{
		length += incrSize;
	}
};

int main()
{
	swimmingPool JacobPool(10, 5, 3, 100);
	JacobPool.printDimentions();
	cout << JacobPool.printPriceOfLand() << endl;
	JacobPool + 5;
	JacobPool.printDimentions();
	system("pause");
	return 0;
}