// 有理数。为有理数实现一个不可变数据类型 Rational，支持加减乘除操作。

#pragma once

#ifndef RATIONNAL_H
#define RATIONNAL_H

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
	Rational(long long numerator, long long denominator);

public:
	Rational plus(Rational rhs);
	Rational minus(Rational &rhs);
	Rational times(Rational &rhs);
	Rational divides(Rational &rhs);

private:
	// 化简
	void Simplification();

private:
	long long m_iNumerator = 0;
	long long m_iDenominator = 1;
};

inline bool Rational::operator==(Rational rhs)
{
	Simplification();
	rhs.Simplification();
	if (m_iNumerator == rhs.m_iNumerator && m_iDenominator == rhs.m_iDenominator)
		return true;

	return false;
}

Rational::Rational(long long numerator, long long denominator) :
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
	lhs.m_iDenominator *= rhs.m_iDenominator;
	lhs.m_iNumerator *= rhs.m_iDenominator;
	rhs.m_iDenominator *= m_iDenominator;
	rhs.m_iNumerator *= m_iDenominator;

	return Rational(lhs.m_iNumerator + rhs.m_iNumerator, lhs.m_iDenominator);
}

inline Rational Rational::minus(Rational & rhs)
{
	Rational lhs = *this;
	// 通分
	lhs.m_iDenominator *= rhs.m_iDenominator;
	lhs.m_iNumerator *= rhs.m_iDenominator;
	rhs.m_iDenominator *= m_iDenominator;
	rhs.m_iNumerator *= m_iDenominator;

	return Rational(lhs.m_iNumerator - rhs.m_iNumerator, lhs.m_iDenominator);
}

inline Rational Rational::times(Rational & rhs)
{
	return Rational(m_iNumerator * rhs.m_iNumerator, m_iDenominator*rhs.m_iDenominator);
}

inline Rational Rational::divides(Rational & rhs)
{
	return Rational(m_iNumerator * rhs.m_iDenominator, m_iDenominator * rhs.m_iNumerator);
}

inline void Rational::Simplification()
{
	// 获取分子和分母的最大公约数
	long long iGcd = gcd(m_iNumerator, m_iDenominator);
	// 化简
	m_iNumerator /= iGcd;
	m_iDenominator /= iGcd;
}

#endif // !RATIONNAL_H
