// ����ַ��� s �е��ַ�ѭ���ƶ�����λ��֮���ܹ��õ���һ���ַ��� t����ô s �ͱ���Ϊ t �Ļػ���λ��circular rotation�������磬ACTGACG ���� TGACGAC ��һ���ػ���λ����֮��Ȼ���ж���������ڻ��������е��о����Ǻ���Ҫ�ġ���дһ�������������������ַ��� s �� t �Ƿ�Ϊ�ػ���λ����ʾ����ֻ��Ҫһ���õ� indexOf()��length() ���ַ������ӵĴ��롣

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isCircularRotation(string s, string t)
{
	if (s.size() != t.size())
		return false;

	s += s;
	if (s.find(t) != string::npos)
		return true;
	else
		return false;
}

int main()
{
	string s = "ACTGACG";
	string t = "TGACGAC";
	cout << boolalpha << isCircularRotation(s, t) << endl;

	return 0;
}