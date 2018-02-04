#include <iostream>

class chair {
private:
	int height;
	int width;
	int depth;
public:
	chair(int x, int y , int z) {
		height = x;
		width = y;
		depth = z;
	};
	int area() { return depth*width;}
};

int main() {
	int entered1, entered2, entered3;
	std::cout << "Enter the dimentions of the chair, height, then width then depth, seperate these by spaces. The area of the seat will be returned:  ";
	std::cin >> entered1 >> entered2 >> entered3;
	chair  myChair(entered1, entered2, entered3);
	std::cout << myChair.area() << std::endl;
	system("pause");
}