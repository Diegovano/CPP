#ifndef QUIZ_DATA_HEADER
#define QUIZ_DATA_HEADER

#include "../event/event.h"
#include <vector>

class QuizData
{
	std::vector<Event> m_questions;
public:
	static std::vector<Event> WW1QuizData(void);
	static std::vector<Event> FranceAnnees30Data(void);

public: //add quiz data to questions
	void AddQuestions(std::vector<Event> events);

public: //getters
	const std::vector<Event>& GetQuestions() const;
};
#endif