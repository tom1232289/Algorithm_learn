#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <vector>
#include <string>

using namespace std;

class StringUtils
{
public:
	// �ַ����ָ�
	static vector<string> split(string str, string pattern);
};

vector<string> StringUtils::split(string str, string pattern)
{
	size_t pos;
	vector<string> result;
	str += pattern;		//��չ�ַ����Է������
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos != string::npos)
		{
			string s = str.substr(i, pos - i);
			result.emplace_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

#endif // !STRING_UTILS_H
