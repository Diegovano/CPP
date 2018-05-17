#include <iostream>
#include <string>

class crypt {
private:
	std::string m_origString, m_convString;//, m_alphabet;						CUSTOM ALPHABET NOT IMPLEMENTED YET.
	int m_shift;
public:
	crypt(std::string p_origString, int p_shift) {					//assigns values to the private members of the class.
		m_origString = p_origString;
		m_shift = p_shift;
	 }
	void M_Encrypt() {
		for (unsigned int index = 0; index < m_origString.length(); index++) {
			int ascii = 0;
			ascii = (int)m_origString.at(index);
//			if (ascii == 32);														//would need to implement getLine functionality for implementation of spaces.		
			if (ascii < 91 && (ascii + m_shift)>90) {					//if the ascii of the char + shift = the ascii of a char 'above' 'z' loop around to 'a'.
				ascii = (ascii += m_shift) - 26;
			}
			else if (ascii < 123 && (ascii + m_shift)>122) {			//if the ascii of the char + shift = the ascii of a char 'above' 'Z' loop around to 'A'.
				ascii = (ascii += m_shift) - 26;
			}
			else {
				ascii += m_shift;
			}
			m_convString += (char)ascii;									//adding the result (coverted char) to the result string.
		}
		std::cout << m_convString << std::endl;
	}
	void M_Decrypt() {
		//for another rainy day... tell me if you read this ;) 
	}
};

int main() {
	std::string entered;
	std::cin >> entered;
	int shift;
	std::cin >> shift;
	crypt encr(entered, shift);
	encr.M_Encrypt();
	system("pause");
/*	char entered;									DEBUG/TESTING
	std::cin >> entered;
	int ascii = (int)entered;
	std::cout << ascii;
	ascii += 5;
	std::cout << (char)ascii;
	conv += entered;
	std::cout << entered.at(index);
	conv += a;
	char a = 'a';
	std::string conv;
	for (unsigned int index = 0; index < entered.length(); index++) {
		int ascii = 0;
		ascii = (int)entered.at(index);
		ascii += 5;
		conv += (char)ascii;
	}
	std::cout << conv << std::endl;*/
}