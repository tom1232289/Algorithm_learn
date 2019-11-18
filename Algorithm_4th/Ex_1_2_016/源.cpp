#include "Rational.h"

int main()
{
	Rational rational1(-3, 4);
	Rational rational2(4, 3);
	auto temp = rational1.plus(rational2);
	auto temp2 = rational1.minus(rational2);
	auto temp3 = rational1.times(rational2);
	auto temp4 = rational1.divides(rational2);

	auto temp5 = rational1 == rational2;
	auto temp6 = rational1 == rational1;

	return 0;
}