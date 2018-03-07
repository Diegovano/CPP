#include <iostream>

class TimeStore
{
	unsigned int seconds, minutes, hours;
public:
	TimeStore(unsigned int hrEnt, unsigned int minEnt, unsigned int secEnt) : hours(hrEnt), minutes(minEnt), seconds(secEnt)
	{
	}
	TimeStore() : seconds(0), minutes(0), hours(0)
	{
	}

	void addSec(unsigned int secAdd)
	{
		seconds += secAdd;
		while (seconds > 59)
		{
			addMin(1);
			seconds -= 60;
		}
	}
	void addMin(unsigned int minAdd)
	{
		minutes += minAdd;
		while (minutes > 59)
		{
			addHr(1);
			minutes -= 60;
		}
	}
	void addHr(unsigned int hrAdd)
	{
		hours += hrAdd;
	}
	void printTimeCont()
	{
		if (hours != 0) std::cout << hours << " Hours, " << minutes << " Minutes and " << seconds << " Seconds." << std::endl;
		else if (minutes != 0) std::cout << minutes << " Minutes and " << seconds << " Seconds." << std::endl;
		else if (seconds != 0) std::cout << seconds << " Seconds." << std::endl;
		else std::cout << "Nothing." << std::endl;
	}
};

int main()
{
	TimeStore tmr1(0, 0, 58);
	tmr1.addSec(1);
	tmr1.printTimeCont();
	system("pause");
	return 0;
}