#ifndef DATE_HEADER
#define DATE_HEADER

enum DateType
{
	YEAR_MONTH_DAY, YEAR_MONTH, YEAR
};

class Date
{
	unsigned int m_day, m_month, m_year;
	DateType m_dateType;
public:
	explicit Date(unsigned int year, unsigned int month, unsigned int day);
	explicit Date(unsigned int year, unsigned int month);
	explicit Date(unsigned int year);
	Date();

public:
	const bool operator==(Date &other) const;

public: //getters
	const unsigned int Day() const;
	const unsigned int Month() const;
	const unsigned int Year() const;
	const DateType GetType() const;
};
#endif