#include "Accumulator.h"

ostream & CAccumulate::print(ostream &os)
{
	os << "Mean:(" << N << " values): ";
	os << fixed << setprecision(7) << mean();
	return os;
}