// 文件列表。文件夹就是一列文件和文件夹的列表。编写一个程序，从命令行接受一个文件夹名作为参数，打印出该文件夹下的所有文件并用递归的方式在所有子文件夹的名下（缩进）列出其下的所有文件。提示：使用队列，并参考 java.io.File。

// C++17遍历目录，没有链表，自带递归迭代器

/**
* 利用c++ 17特性遍历目录
*/
#include<iostream>
#include<filesystem>

using namespace std;
#if _MSC_VER == 1900
using namespace std::experimental;	// VS2015中filesystem放在experimental下
#endif

void processPath(const filesystem::path& p)
{
	if (!exists(p)) {         // 目录不存在直接返回
		return;
	}
	auto begin = filesystem::recursive_directory_iterator(p); // 获取文件系统迭代器
	auto end = filesystem::recursive_directory_iterator();    // end迭代器
	for (auto it = begin; it != end; it++) {
		const string spacer(it.depth(), '-');  // 这个是用来排版的空格
		auto& entry = *it;
		// 如果是文件
		if (filesystem::is_regular_file(entry)) {
			cout << spacer << "File:" << entry;
			cout << "(" << filesystem::file_size(entry) << " bytes )" << endl;
		}
		// 如果是目录
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