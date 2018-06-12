#include "quizData.h"

QuizData::~QuizData()
{
	delete &m_questions;
}

std::vector<Event*> QuizData::WW1(void)
{
	std::vector<Event*> dateContainer;
	dateContainer.push_back(new Event("de la mort de Franz Ferdinand", Date(1914, 6, 28)));
	dateContainer.push_back(new Event("de la 1ere Guerre Mondiale", Date(1914, 7, 28), Date(1918, 11, 11)));
	dateContainer.push_back(new Event("de l'entree des Etats-Unis en guerre", Date(1917)));
	dateContainer.push_back(new Event("de la Battaile de Verdun", Date(1916, 2), Date(1916, 12)));
	dateContainer.push_back(new Event("de la Battaille de la Somme", Date(1916, 7), Date(1916, 11)));
	dateContainer.push_back(new Event("du Genocide Armenien", Date(1915), Date(1917)));
	dateContainer.push_back(new Event("du Traite de Versailles", Date(1919), Date(1920)));

	return dateContainer;
}

std::vector<Event*> QuizData::FranceAnnees30(void)
{
	std::vector<Event*> dateContainer;
	dateContainer.push_back(new Event("de la manifestation de l'extreme droite", Date(1934, 2, 6)));
	dateContainer.push_back(new Event("du krash Boursier", Date(1929)));
	dateContainer.push_back(new Event("de l'election de Leon Blum", Date(1936)));
	dateContainer.push_back(new Event("de la signature des accords Matignon", Date(1936, 6, 7)));
	
	return dateContainer;
}

std::vector<Event*> QuizData::FrancePdtWW2(void)
{
	std::vector<Event*> dateContainer;
	dateContainer.push_back(new Event("de la bataille de la France", Date(1940, 5), Date(1940, 6)));
	dateContainer.push_back(new Event("de la signature de l'armistice (francaise)", Date(1940, 6, 22)));
	dateContainer.push_back(new Event("de l'entrevue de Montojoie", Date(1940, 10)));
	dateContainer.push_back(new Event("de la liberation de Paris", Date(1944, 8)));

	return dateContainer;
}

std::vector<Event*> QuizData::GuerreAlgerieEtVe(void)
{
	std::vector<Event*> dateContainer;
	dateContainer.push_back(new Event("de la Guerre D'Algerie", Date(1954, 11, 1), Date(1962, 9, 9)));
	dateContainer.push_back(new Event("du coup d'etat a Algers", Date(1958, 5, 13)));
	dateContainer.push_back(new Event("de la naissance de la Veme Republique", Date(1958)));

	return dateContainer;
}

void QuizData::AddQuestions(std::vector<Event*> events)
{
	m_questions.insert(std::end(m_questions), std::begin(events), std::end(events));
}

const std::vector<Event*>& QuizData::GetQuestions() const
{
	return m_questions;
}