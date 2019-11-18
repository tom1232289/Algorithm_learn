// Ϊ SmartDate ���һ������ dayOfTheWeek()��Ϊ������ÿ�ܵ��շ��� Monday��Tuesday��Wednesday��Thursday��Friday��Saturday ��Sunday �е��ʵ�ֵ������Լٶ�ʱ���� 21 ���͡�

#pragma once

#ifndef SMART_DATE_H
#define SMART_DATE_H

#include <vector>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

class SmartDate
{
	enum WEEK { Sunday = 0, Monday, Thesday, Wednesday, Thursday, Friday, Saturday };
public:
	SmartDate(int year, int month, int day) :
		year(year),
		month(month),
		day(day)
	{
		if (!isValid()) {
			LogError("invalid date");
		}
	}

public:
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	WEEK dayOfTheWeek();	// ʹ�ò��չ�ʽ

private:
	bool isValid();

private:
	int year = 0;
	int month = 0;
	int day = 0;
	std::vector<int> months = { 31,29,31,30,31,30,31,31,30,31,30,31 };
};

SmartDate::WEEK SmartDate::dayOfTheWeek()
{
	if (month == 1 || month == 2) {
		month += 12;
		--year;
	}

	int c = year / 100;	// ���ǰ��λ
	int y = year % 100;	// ��ݺ���λ
	int w = (y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1);	// ���չ�ʽ
	w = (w % 7 + 7) % 7;

	return (WEEK)w;
}

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
