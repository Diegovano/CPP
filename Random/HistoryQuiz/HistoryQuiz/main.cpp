#include "src/quizCore/quizCore.h"
#include <iostream>

int main(int argc, char* argv[])
{
	QuizCore quiz;
	unsigned int sel;
	std::cout << "Combien de questions? Entrez '0' pour avoir toutes les questions possibles. ";
	std::cin >> sel;
	if (sel == 0) sel = quiz.GetNoQuestions() - 1; //for loop starts at 0
	for (unsigned int i = 0; i < sel; i++)
	{
		bool correct = false;
		Event currentQuestion = quiz.GetRandEvent();
		unsigned int year, month, day;
		std::cout << "Quelle etait la date ";
		std::cout << currentQuestion.GetName() << std::endl;
		std::cout << "On attend ";
		switch (currentQuestion.GetDate().GetType())
		{
		case(YEAR_MONTH_DAY): std::cout << "Le jour, ";
		case(YEAR_MONTH): std::cout << "le mois et ";
		case(YEAR): std::cout << "l'annee.\n";
		}
		switch (currentQuestion.GetDate().GetType())
		{
		case(YEAR_MONTH_DAY): 	
			std::cin >> day >> month >> year;
			if (currentQuestion.GetDate().Year() == year &&
			currentQuestion.GetDate().Month() == month && currentQuestion.GetDate().Day() == day)
			correct = true;
			break;
		case(YEAR_MONTH): 
			std::cin >> month >> year;
			if (currentQuestion.GetDate().Year() == year &&
			currentQuestion.GetDate().Month() == month)
			correct = true;
			break;
		case(YEAR): 
			std::cin >> year;
			if (currentQuestion.GetDate().Year() == year) correct = true;
		}
		if (currentQuestion.IsRanged() && correct)
		{
			std::cout << "Jusqu'a?\n";
			switch (currentQuestion.GetDate().GetType())
			{
			case(YEAR_MONTH_DAY):
				std::cin >> day >> month >> year;
				if (currentQuestion.GetEnd().Year() == year &&
					currentQuestion.GetEnd().Month() == month && currentQuestion.GetEnd().Day() == day)
					correct = true;
				else correct = false;
				break;
			case(YEAR_MONTH):
				std::cin >> month >> year;
				if (currentQuestion.GetEnd().Year() == year &&
					currentQuestion.GetEnd().Month() == month)
					correct = true;
				else correct = false;
				break;
			case(YEAR):
				std::cin >> year;
				if (currentQuestion.GetEnd().Year() == year) correct = true;
				else correct = false;
			}

		}
		if (!correct) std::cout << "Faux.";
		else std::cout << "Vrai!";
		std::cout << std::endl << std::endl;
	}
	system("pause");
	return 0;
}