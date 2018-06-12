#ifndef QUIZ_DATA_HEADER
#define QUIZ_DATA_HEADER

#include "../event/event.h"
#include <vector>

class QuizData
{
	std::vector<Event*> m_questions;
public:
	~QuizData();

	static std::vector<Event*> WW1(void);
	static std::vector<Event*> FranceAnnees30(void);
	static std::vector<Event*> FrancePdtWW2(void);
	static std::vector<Event*> GuerreAlgerieEtVe(void);

public: //add quiz data to questions
	void AddQuestions(std::vector<Event*> events);

public: //getters
	const std::vector<Event*>& GetQuestions() const;
};
#endif