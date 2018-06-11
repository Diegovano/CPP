#include "quizData.h"

std::vector<Event> QuizData::WW1QuizData(void)
{
	std::vector<Event> dateContainer;
	dateContainer.push_back(*new Event("de la mort de Franz Ferdinand", Date(1914, 6, 28)));
	dateContainer.push_back(*new Event("de la 1ere Guerre Mondiale", Date(1914, 7, 28), Date(1918, 11, 11)));
	dateContainer.push_back(*new Event("de l'entree des Etats-Unis en guerre", Date(1917)));
	dateContainer.push_back(*new Event("de la Battaile de Verdun", Date(1916, 2), Date(1916, 12)));
	dateContainer.push_back(*new Event("de la Battaille de la Somme", Date(1916, 7), Date(1916, 11)));
	dateContainer.push_back(*new Event("du Genocide Armenien", Date(1915), Date(1917)));
	dateContainer.push_back(*new Event("du Traite de Versailles", Date(1919), Date(1920)));

	return dateContainer;
}

void QuizData::AddQuestions(std::vector<Event> events)
{
	m_questions.insert(std::end(m_questions), std::begin(events), std::end(events));
}

const std::vector<Event>& QuizData::GetQuestions() const
{
	return m_questions;
}