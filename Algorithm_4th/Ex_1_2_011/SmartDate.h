// 根据 Date 的 API 实现一个 SmartDate 类型，在日期非法时抛出一个异常。

#pragma once

#ifndef SMART_DATE_H
#define SMART_DATE_H

#include <vector>

class SmartDate
{
public:
	SmartDate(int year, int month, int day) :
		year(year),
		month(month),
		day(day)
	{
		if (!isValid()) {
			throw "invalid date";
		}
	}

public:
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

private:
	bool isValid();

private:
	int year = 0;
	int month = 0;
	int day = 0;
	std::vector<int> months = { 31,29,31,30,31,30,31,31,30,31,30,31 };
};

bool SmartDate::isValid()
{
	if (month < 1 || month > 12)
		return false;

	if (day<1 || day>months.at(month - 1))
		return false;

	if (year % 4 != 0 && month == 2 && day > 28)
		return false;

	return true;
}

#endif // !SMART_DATE_H
