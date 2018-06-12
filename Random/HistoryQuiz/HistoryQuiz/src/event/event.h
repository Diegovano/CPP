#ifndef EVENT_HEADER
#define EVENT_HEADER

#include "../date/date.h"

class Event
{
	const char * m_name;
	Date m_begin;
	Date m_end;
	bool m_rangedEvent;
public:
	explicit Event(const char * name, Date begin);
	explicit Event(const char * name, Date begin, Date end);

	~Event();

public:
	bool CheckDate(Date checkBegin);
	bool CheckRanged(Date checkBegin, Date checkEnd);

public: //getters
	const Date GetDate() const;
	const Date GetEnd() const;
	const char* GetName() const;
	const bool IsRanged() const;
};
#endif