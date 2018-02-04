#include <iostream>
#include <string>
//#include <fstream>

class Currency {
	double m_valueToGDP;
public:
	std::string m_name, m_symbol;
	Currency(std::string p_name, double p_valueToGDP, std::string p_symbol) {
		m_name = p_name;
		m_valueToGDP = p_valueToGDP;
		m_symbol = p_symbol;
	}
	double convToGDP(double p_toConv) {
		return p_toConv*m_valueToGDP;
	}
	double conv(double p_valInGDP) {
		return p_valInGDP / m_valueToGDP;
	}
};

int main() {
	std::string entered, entered1, toConvFrom;
	double entered2, resultOfConv;
	std::string USD = "United States Dollar";
	std::string EUR = "Euro";
	std::string SEK = "Swedish Krona";
	std::string AUD = "Australian Dollar";
	std::string RUB = "Russian Ruble";
	Currency _USD(USD, 0.74, "$");
	Currency _EUR(EUR, 0.88, "€");
	Currency _SEK(SEK, 0.092, "SEK");
	Currency _AUD(AUD, 0.59, "AU$");
	Currency _RUB(RUB, 0.013, "RUB");
	std::cout << "Enter the name of the currency you wish to convert from: ";
	std::cin >> entered;
	std::cout << "\nType the name of the currecny that you want to convert to: ";
	std::cin >> entered1;
	std::cout << "\nEnter the value you wish to convert: ";
	std::cin >> entered2;
		if (entered == "USD" || entered == "usd") {
			resultOfConv = _USD.convToGDP(entered2);
		}
		else if (entered == "EUR" || entered == "eur") {
			resultOfConv = _EUR.convToGDP(entered2);
		}
		else if (entered == "SEK" || entered == "sek") {
			resultOfConv = _SEK.convToGDP(entered2);
		}
		else if (entered == "AUD" || entered == "aud") {
			resultOfConv = _AUD.convToGDP(entered2);
		}
		else if (entered == "RUB" || entered == "rub") {
			resultOfConv = _RUB.convToGDP(entered2);
		}
		else {
			std::cout << "Incorrect entry.\n";
		}
		std::cout << "The result of you conversion from " << entered << " to " << entered1 << " is: ";
		if (entered1 == "USD" || entered1 == "usd") {
			std::cout << _USD.m_symbol << _USD.conv(resultOfConv);
		}
		else if (entered1 == "EUR" || entered1 == "eur") {
			std::cout << _EUR.m_symbol << _EUR.conv(resultOfConv);
		}
		else if (entered1 == "SEK" || entered1 == "sek") {
			std::cout << _SEK.m_symbol << _SEK.conv(resultOfConv);
		}
		else if (entered1 == "AUD" || entered1 == "aud") {
			std::cout << _AUD.m_symbol << _AUD.conv(resultOfConv);
		}
		else if (entered1 == "RUB" || entered1 == "rub") {
			std::cout << _RUB.m_symbol << _RUB.conv(resultOfConv);
		}
		else if (entered1 == "GBP" || entered1 == "gbp") {
			std::cout << "£" << resultOfConv;
		}
		else {
			std::cout << "Incorrect entry.\n";
		std::cout << std::endl;
		}
	system("pause");
	return 0;
}