#include "quizCore.h"

QuizCore::QuizCore() : m_quiz(*new QuizData), m_timesAsked(0), m_askedQuestionsIndex(new int[m_quiz.GetQuestions().size()])
{
	m_quiz.AddQuestions(QuizData::WW1QuizData());
	m_quiz.AddQuestions(QuizData::FranceAnnees30Data());
}

const Event QuizCore::GetRandEvent()
{
	unsigned int randIndex;
	if (m_timesAsked < m_quiz.GetQuestions().size())
	{
		randIndex = rand() % m_quiz.GetQuestions().size();
		for (int i2 = 0; i2 < (int)m_quiz.GetQuestions().size(); i2++)
		{
			if (m_askedQuestionsIndex[i2] == randIndex)
			{
				randIndex = rand() % m_quiz.GetQuestions().size();
				i2 = -1; //so i2 = 0 on next for loop run
			}
		}
		m_askedQuestionsIndex[m_timesAsked] = randIndex;
		m_timesAsked++;
		return m_quiz.GetQuestions().at(randIndex);
	}
	else
	{
		m_askedQuestionsIndex = new int[m_quiz.GetQuestions().size()];
		m_timesAsked = 0;
		return this->GetRandEvent();
	}
}
const unsigned int QuizCore::GetNoQuestions() const
{
	return m_quiz.GetQuestions().size();
}
