#include <iostream>

class Triangle {
	double m_base, m_height, m_distHeight;
public:
	Triangle(double p_base, double p_height, double p_distHeight) {
		m_base = p_base;
		m_height = p_height;
		m_distHeight = p_distHeight;
	}
	double M_area() {
		return m_height*(m_base - m_distHeight) / 2 + m_height*m_distHeight / 2;
	}
	double M_pyt(double p_pytBase1, double p_pytHeight2) {
		p_pytBase1 = p_pytBase1*p_pytBase1;
		p_pytHeight2 = p_pytHeight2*p_pytHeight2;
		return sqrt(p_pytBase1 + p_pytHeight2);
	}
	double M_perimeter() {
		return m_base + M_pyt(m_base - m_distHeight, m_height) + M_pyt(m_distHeight, m_height);
	}
};

class Square {
	double m_side;
public:
	Square(double p_side) {
		m_side = p_side;
	}
	double M_area() {
		return m_side * m_side;
	}
	double M_perimeter() {
		return m_side * 4;
	}
};

class Rectangle {
	double m_srtSide, m_lngSide;
public:
	Rectangle(double p_srtSide, double p_lngSide) {
		if (p_srtSide < p_lngSide || p_srtSide == p_lngSide) {
			m_srtSide = p_srtSide;
			m_lngSide = p_lngSide;
		}
		else if (p_srtSide > p_lngSide) {
			m_srtSide = p_lngSide;
			m_lngSide = p_srtSide;
		}
	}
	double M_area() {
		return m_lngSide*m_srtSide;
	}
	double M_perimeter() {
		return m_lngSide * 2 + m_srtSide * 2;
	}
};

int main() {
	double imp1, imp2, imp3;
	std::cout << "Please Enter Up to Three Values Seperated by Spaces. Enter Three Even if You Are Calculating Areas/Perimeters For Squares or Rectangles, in This Case, Assign the THIRD Value Randomly For Rectangles and the SECOND and THIRD Randomly for Squares.\n";
	std::cout << "Entered Numbers: ";
	std::cin >> imp1 >> imp2 >> imp3;
	Triangle myTri(imp1, imp2, imp3);
	Square mySqr(imp1);
	Rectangle myRect(imp1, imp2);
	std::cout << "\nData For Triangles:\nArea: " << myTri.M_area() << "\nPerimeter: " << myTri.M_perimeter() << "\n\n";
	std::cout << "Data For Squares:\nArea: " << mySqr.M_area() << "\nPrimeter: " << mySqr.M_perimeter() << "\n\n";
	std::cout << "Data For Rectangles:\nArea: " << myRect.M_area() << "\nPerimeter: " << myRect.M_perimeter() << "\n\n";
	system("pause");
}