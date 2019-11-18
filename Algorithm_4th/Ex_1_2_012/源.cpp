#include "SmartDate.h"
#include <iostream>

int main()
{
	SmartDate sd(2020, 1, 1);

	std::cout << sd.dayOfTheWeek() << std::endl;

	return 0;
}