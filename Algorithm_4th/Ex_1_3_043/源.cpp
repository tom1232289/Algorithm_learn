// �ļ��б��ļ��о���һ���ļ����ļ��е��б���дһ�����򣬴������н���һ���ļ�������Ϊ��������ӡ�����ļ����µ������ļ����õݹ�ķ�ʽ���������ļ��е����£��������г����µ������ļ�����ʾ��ʹ�ö��У����ο� java.io.File��

// C++17����Ŀ¼��û�������Դ��ݹ������

/**
* ����c++ 17���Ա���Ŀ¼
*/
#include<iostream>
#include<filesystem>

using namespace std;
#if _MSC_VER == 1900
using namespace std::experimental;	// VS2015��filesystem����experimental��
#endif

void processPath(const filesystem::path& p)
{
	if (!exists(p)) {         // Ŀ¼������ֱ�ӷ���
		return;
	}
	auto begin = filesystem::recursive_directory_iterator(p); // ��ȡ�ļ�ϵͳ������
	auto end = filesystem::recursive_directory_iterator();    // end������
	for (auto it = begin; it != end; it++) {
		const string spacer(it.depth(), '-');  // ����������Ű�Ŀո�
		auto& entry = *it;
		// ������ļ�
		if (filesystem::is_regular_file(entry)) {
			cout << spacer << "File:" << entry;
			cout << "(" << filesystem::file_size(entry) << " bytes )" << endl;
		}
		// �����Ŀ¼
		else if (filesystem::is_directory(entry)) {
			cout << spacer << "Dir:" << entry << endl;
		}
	}
}

int main()
{
	filesystem::path p(R"(C:\Windows)");
	processPath(p);
	return 0;
}