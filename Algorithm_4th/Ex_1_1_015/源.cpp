// ��дһ����̬����histogram()������һ����������a[] ��һ������M Ϊ����������һ����СΪM�����飬���е�i��Ԫ�ص�ֵΪ����i�ڲ��������г��ֵĴ��������a[]�е�ֵ����0��M - 1֮�䣬��������������Ԫ��֮��Ӧ�ú�a.length ��ȡ�

#include <iostream>
#include <vector>

using namespace std;

vector<int> histogram(vector<int> &vec)
{
	size_t M = vec.size();
	vector<int> retVec(M, 0);
	for (size_t i = 0; i < M; ++i) {
		int iTimes = 0;
		for (size_t j = 0; j < M; ++j) {
			if (vec[j] == i) {
				++iTimes;
			}
		}
		retVec[i] = iTimes;
	}
	return retVec;
}

int main()
{
	vector<int> ivec = { 1,1,3,2,1,2 };
	vector<int> ivec2 = histogram(ivec);
	for (auto iter = ivec2.begin(); iter != ivec2.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}