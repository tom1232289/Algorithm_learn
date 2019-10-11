#include "Rational.h"

int main()
{
	Rational rational1(-2147483641, 4);
	Rational rational2(4, 3);
	auto temp = rational1.plus(rational2);
	auto temp2 = rational1.minus(rational2);
	auto temp3 = rational1.times(rational2);
	auto temp4 = rational1.divides(rational2);

	return 0;
}