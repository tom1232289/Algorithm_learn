#include "DoubleUtils.h"
#include <math.h>

int getScaleLen(double value)
{
	char str[51] = { 0 };
	_snprintf_s(str, 50, "%.10lf", value);
	size_t j = strlen(str);
	size_t i = j - 1;
	while (str[i] == '0')
		str[i--] = '\0';

	int length = 0;
	while (str[i] != '.')
	{
		i--;
		length++;
	}
	return length;
}

double getScale(double value)
{
	char str[51] = { 0 };
	_snprintf_s(str, 50, "%.10lf", value);
	size_t j = strlen(str);
	size_t i = j - 1;
	while (str[i] == '0')
		str[i--] = '\0';

	int length = 0;
	while (str[i] != '.')
	{
		i--;
		length++;
	}

	double base = 1;

	for (int i = 0; i < length; i++)
	{
		base = base / 10;
	}
	return base;
}

double getScale(const char* value, bool ignoreTailZero)
{
	char str[50] = { 0 };
	strcpy_s(str, value);
	size_t j = strlen(str);
	size_t i = j - 1;
	while (str[i] == '0' && ignoreTailZero)
		str[i--] = '\0';

	int length = 0;
	while (str[i] != '.')
	{
		i--;
		length++;
	}

	double base = 1;

	for (int i = 0; i < length; i++)
	{
		base = base / 10;
	}
	return base;
}

double myRound(double r)
{
	return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

double myRound(double value, int scale)
{
	double base = 1;
	for (int i = 0; i < scale; i++)
	{
		base = 10 * base;
	}
	return myRound(value * base) / base;
}

double myFloor(double value, int scale)
{
	double base = 1;
	for (int i = 0; i < scale; i++)
	{
		base = 10 * base;
	}
	return floor(value * base) / base;
}
double myCeil(double value, int scale)
{
	double base = 1;
	for (int i = 0; i < scale; i++)
	{
		base = 10 * base;
	}
	return ceil(value * base) / base;
}
double mySub(double a, double b)
{
	int len = getScaleLen(b) > getScaleLen(a) ? getScaleLen(b) : getScaleLen(a);
	return myRound(a - b, len);
}

double myAdd(double a, double b)
{
	int len = getScaleLen(b) > getScaleLen(a) ? getScaleLen(b) : getScaleLen(a);
	return myRound(a + b, len);
}

std::string doubleToString(double value)
{
	char buf[31] = { 0 };
	_snprintf_s(buf, 30, "%.10lf", value);
	size_t i = strlen(buf) - 1;
	while (buf[i] == '0')
		buf[i--] = '\0';

	if (buf[i] == '.')
	{
		buf[i] = '\0';
	}
	return std::string(buf);
}