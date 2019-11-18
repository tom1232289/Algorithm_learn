#pragma once

#ifndef LOG_INFO_H
#define LOG_INFO_H

#include <iostream>
#include <string>

using namespace std;

namespace LogInfo
{
	// 函数声明
	void LogError(string str);
	void LogDebug(string str);
	void Log(string str);

	// 函数定义
	void LogError(string str)
	{
		LogDebug(str);
#ifdef _DEBUG
		abort();
#else
		exit(-1);
#endif
	}

	void LogDebug(string str)
	{
		cerr << str << endl;
	}

	void Log(string str)
	{
		cout << str << endl;
	}
}

#endif // !LOG_INFO_H
