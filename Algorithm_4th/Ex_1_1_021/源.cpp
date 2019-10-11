#include "SheetRow.h"
#include <fstream>
#include <sstream>
#include <vector>

vector<SheetRow> GetSheetRow(ifstream &in)
{
	vector<SheetRow> srVec;
	string line;
	while (getline(in, line)) {
		string word;
		istringstream is(line);
		vector<string> svec;
		while (is >> word) {
			svec.push_back(word);
		}
		SheetRow sr(svec.at(0), stoi(svec.at(1)), stoi(svec.at(2)));
		srVec.push_back(sr);
	}
	return srVec;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "缺少输入文件" << endl;
		return 0;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法读取输入文件" << endl;
		return 0;
	}

	vector<SheetRow> srVec = GetSheetRow(in);
	for (auto c : srVec) {
		c.print(cout);
		cout << endl;
	}

	return 0;
}