// 有理数实现的健壮性。在Rational（请见练习 1.2.16）的开发中使用断言来防止溢出。

#pragma once

#ifndef RATIONNAL_H
#define RATIONNAL_H

#include <string>
#include <assert.h>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

// 最大公约数
int gcd(int p, int q)
{
	if (q == 0)
		return p;

	int r = p % q;
	return gcd(q, r);
}

class Rational
{
public:
	bool operator==(Rational rhs);

public:
	Rational(int numerator, int denominator);

public:
	Rational plus(Rational rhs);
	Rational minus(Rational rhs);
	Rational times(Rational rhs);
	Rational divides(Rational rhs);

private:
	// 化简
	void Simplification();
	// 判断溢出
	bool isOverflow(int lhs, int rhs, std::string sOperator);

private:
	int m_iNumerator = 0;
	int m_iDenominator = 1;
};

inline bool Rational::operator==(Rational rhs)
{
	Simplification();
	rhs.Simplification();
	if (m_iNumerator == rhs.m_iNumerator && m_iDenominator == rhs.m_iDenominator)
		return true;

	return false;
}

Rational::Rational(int numerator, int denominator) :
	m_iNumerator(numerator),
	m_iDenominator(denominator)
{
	// 分母为0
	if (m_iDenominator == 0)
		LogError("denominator is zero");

	Simplification();
}

inline Rational Rational::plus(Rational rhs)
{
	Rational lhs = *this;
	// 通分
	assert(!isOverflow(lhs.m_iDenominator, rhs.m_iDenominator, "*"));
	lhs.m_iDenominator *= rhs.m_iDenominator;
	assert(!isOverflow(lhs.m_iNumerator, rhs.m_iDenominator, "*"));
	lhs.m_iNumerator *= rhs.m_iDenominator;
	assert(!isOverflow(rhs.m_iDenominator, m_iDenominator, "*"));
	rhs.m_iDenominator *= m_iDenominator;
	assert(!isOverflow(rhs.m_iDenominator, m_iDenominator, "*"));
	rhs.m_iNumerator *= m_iDenominator;

	assert(!isOverflow(lhs.m_iNumerator, rhs.m_iNumerator, "+"));
	int numerator = lhs.m_iNumerator + rhs.m_iNumerator;
	int denominator = lhs.m_iDenominator;

	return Rational(numerator, denominator);
}

inline Rational Rational::minus(Rational  rhs)
{
	Rational lhs = *this;
	// 通分
	assert(!isOverflow(lhs.m_iDenominator, rhs.m_iDenominator, "*"));
	lhs.m_iDenominator *= rhs.m_iDenominator;
	assert(!isOverflow(lhs.m_iNumerator, rhs.m_iDenominator, "*"));
	lhs.m_iNumerator *= rhs.m_iDenominator;
	assert(!isOverflow(rhs.m_iDenominator, m_iDenominator, "*"));
	rhs.m_iDenominator *= m_iDenominator;
	assert(!isOverflow(rhs.m_iNumerator, m_iDenominator, "*"));
	rhs.m_iNumerator *= m_iDenominator;

	assert(!isOverflow(lhs.m_iNumerator, rhs.m_iNumerator, "-"));
	int numerator = lhs.m_iNumerator - rhs.m_iNumerator;
	int denominator = lhs.m_iDenominator;

	return Rational(numerator, denominator);
}

inline Rational Rational::times(Rational  rhs)
{
	assert(!isOverflow(m_iNumerator, rhs.m_iNumerator, "*"));
	int numerator = m_iNumerator * rhs.m_iNumerator;
	assert(!isOverflow(m_iDenominator, rhs.m_iDenominator, "*"));
	int denominator = m_iDenominator * rhs.m_iDenominator;

	return Rational(numerator, denominator);
}

inline Rational Rational::divides(Rational  rhs)
{
	assert(!isOverflow(m_iNumerator, rhs.m_iDenominator, "*"));
	int numerator = m_iNumerator * rhs.m_iDenominator;
	assert(!isOverflow(m_iDenominator, rhs.m_iNumerator, "*"));
	int denominator = m_iDenominator * rhs.m_iNumerator;

	return Rational(numerator, denominator);
}

inline void Rational::Simplification()
{
	// 获取分子和分母的最大公约数
	long long iGcd = gcd(m_iNumerator, m_iDenominator);
	// 化简
	m_iNumerator /= iGcd;
	m_iDenominator /= iGcd;
}

inline bool Rational::isOverflow(int lhs, int rhs, std::string sOperator)
{
	if (sOperator == "+") {
		int result = lhs + rhs;
		if (lhs > 0 && rhs > 0 && result < 0)
			return true;
		else if (lhs < 0 && rhs < 0 && result > 0)
			return true;
	}
	else if (sOperator == "-") {
		int result = lhs - rhs;
		if (lhs > 0 && rhs < 0 && result < 0)
			return true;
		else if (lhs < 0 && rhs > 0 && result > 0)
			return true;
	}
	else if (sOperator == "*") {
		int result = lhs * rhs;
		if (result / rhs != lhs)
			return true;
	}
	else if (sOperator == "/") {
		int result = lhs / rhs;
		if (result * rhs != lhs)
			return true;
	}

	return false;
}

#endif // !RATIONNAL_H
