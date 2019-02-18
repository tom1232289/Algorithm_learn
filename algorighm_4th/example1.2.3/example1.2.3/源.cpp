#include <iostream>
#include "Counter.h"

int main()
{
	Counter heads("heads");
	Counter tails("tails");

	heads.increment();
	heads.increment();
	tails.increment();

	cout << heads.toString() + " " + tails.toString() << endl;
	cout << heads.tally() + tails.tally() << endl;

	system("pause");
	return 0;
}