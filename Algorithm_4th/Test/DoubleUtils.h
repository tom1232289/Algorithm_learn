//---------------------------------------------------------------------------

#ifndef DoubleUtilsH
#define DoubleUtilsH
//---------------------------------------------------------------------------
#include <string>

int getScaleLen(double value);
double getScale(double value);
double getScale(const char* value, bool ignoreTailZero);
double myRound(double r);
double myRound(double value, int scale);
double myFloor(double value, int scale);
double myCeil(double value, int scale);
double mySub(double a, double b);
double myAdd(double a, double b);
std::string doubleToString(double value);

#endif
