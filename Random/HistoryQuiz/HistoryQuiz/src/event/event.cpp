#include "event.h"

Event::Event(const char * name, Date begin)
	: m_name(name), m_begin(begin), m_rangedEvent(false)
{

}
Event::Event(const char * name, Date begin, Date end)
	: m_name(name), m_begin(begin), m_end(end), m_rangedEvent(true)
{

}

Event::~Event()
{
	
}

bool Event::CheckDate(Date checkBegin)
{
	if (checkBegin == m_begin) return true;
	return false;
}
bool Event::CheckRanged(Date checkBegin, Date checkEnd)
{
	if (checkBegin == m_begin && checkEnd == m_end) return true;
	return false;
}
const Date Event::GetDate() const
{
	return m_begin;
}
const Date Event::GetEnd() const
{
	return m_end;
}
const char* Event::GetName() const
{
	return m_name;
}
const bool Event::IsRanged() const
{
	return m_rangedEvent;
}