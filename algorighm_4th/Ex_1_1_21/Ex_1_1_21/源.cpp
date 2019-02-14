#include <iostream>
#include <fstream>
#include <sstream>
#include "SheetRow.h"
#include <string>

using namespace std;

vector<CSheetRow> GetSheetRow(ifstream &in)
{
	vector<CSheetRow> srVec;
	string line;
	while (getline(in, line)) {
		string word;
		istringstream is(line);
		vector<string> svec;
		while (is >> word) {
			svec.push_back(word);
		}
		CSheetRow sr;
		sr.sName = svec[0];
		sr.i = stod(svec[1]);
		sr.j = stod(svec[2]);
		sr.k = sr.i / sr.j;
		srVec.push_back(sr);
	}
	return srVec;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "ȱ�������ļ�" << endl;
		return 0;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷���ȡ�����ļ�" << endl;
		return 0;
	}
	vector<CSheetRow> srVec = GetSheetRow(in);
	for (auto c : srVec) {
		c.print(cout);
		cout << endl;
	}

	system("pause");
	return 0;
}