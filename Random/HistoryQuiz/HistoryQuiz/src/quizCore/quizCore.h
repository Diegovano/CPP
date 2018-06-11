#ifndef QUIZ_CORE_HEADER
#define QUIZ_CORE_HEADER

#include "../quizData/quizData.h"

class QuizCore
{
	QuizData m_quiz;
	int* m_askedQuestionsIndex;
	unsigned int m_timesAsked;
public:
	QuizCore();

public:
	const Event GetRandEvent();

public: //getters
	const unsigned int GetNoQuestions() const;
};
#endif