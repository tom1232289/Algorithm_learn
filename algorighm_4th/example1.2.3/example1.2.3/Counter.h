#pragma once

#include <string>

using namespace std;

class Counter
{
public:
	Counter(string id):
		name(id){	}
public:
	void increment() { count++; }
	int tally() { return count; }
	string toString() { return to_string(count) + " " + name; }
private:
	const string name;
	int count = 0;
};