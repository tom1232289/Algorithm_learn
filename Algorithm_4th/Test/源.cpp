//// 求最大公约数
//// 自然语言描述:计算两个非负整数p 和q 的最大公约数：若q 是0，则最大公约数为p。否则，将p 除以q 得到余数r，p 和q 的最大公约数即为q 和r 的最大公约数。
int gcd(int p, int q)
{
	if (q == 0)
		return p;

	int r = p % q;
	return gcd(q, r);
}
//
////import java.util.Arrays;
////public class BinarySearch
////{
////	public static int rank(int key, int[] a)
////	{ // 数组必须是有序的
////		int lo = 0;
////		int hi = a.length - 1;
////		while (lo <= hi)
////		{ // 被查找的键要么不存在，要么必然存在于a[lo..hi] 之中
////			int mid = lo + (hi - lo) / 2;
////			if (key < a[mid]) hi = mid - 1;
////			else if (key > a[mid]) lo = mid + 1;
////			else return mid;
////		}
////		return -1;
////	}
////	public static void main(String[] args)
////	{
////		int[] whitelist = In.readInts(args[0]);
////		Arrays.sort(whitelist);
////		while (!StdIn.isEmpty())
////		{ // 读取键值，如果不存在于白名单中则将其打印
////			int key = StdIn.readInt();
////			if (rank(key, whitelist) < 0)
////				StdOut.println(key);
////		}
////	}
////}
//
////编写一段代码，将一个正整数N 用二进制表示并转换为一个String 类型的值s。
////解答：Java 有一个内置方法Integer.toBinaryString(N) 专门完成这个任务，但该题的目的就
////是给出这个方法的其他实现方法。下面就是一个特别简洁的答案：
////String s = "";
////for (int n = N; n > 0; n /= 2)
////s = (n % 2) + s;
//
//#include <iostream>
//#include <malloc.h>
//#include <string>
//using namespace std;
//
//// 静态队列[循环队列] 也叫数组队列
//template<typename _Ty, int LEN>
//class LoopQueue
//{
//public:
//	LoopQueue();
//	~LoopQueue();
//
//public:
//	bool	IsEmpty();			// 队列是否为空
//	bool	IsFull();			// 队列是否已满
//	bool	push_back(_Ty val);	// 添加元素到队尾
//	_Ty		front();			// 获得队列第一个元素
//	bool	pop_front();		// 弹出第一个元素
//
//private:
//	int		m_front;			// 数组第一个元素下标
//	int		m_rear;				// 数组最后一个元素下标
//	_Ty		m_queue[LEN + 1];		// 循环队列
//};
//
//template<typename _Ty, int LEN>
//LoopQueue<_Ty, LEN>::LoopQueue()
//{
//	m_front = m_rear = 0;
//}
//
//template<typename _Ty, int LEN>
//LoopQueue<_Ty, LEN>::~LoopQueue()
//{
//	delete[] m_queue;
//}
//
//template<typename _Ty, int LEN>
//bool LoopQueue<_Ty, LEN>::IsEmpty()
//{
//	return &m_queue[m_front] == &m_queue[m_rear] ? true : false;
//}
//
//template<typename _Ty, int LEN>
//bool LoopQueue<_Ty, LEN>::IsFull()
//{
//	return (m_rear + 1) % (LEN + 1) == m_front ? true : false;
//}
//
//template<typename _Ty, int LEN>
//bool LoopQueue<_Ty, LEN>::push_back(_Ty val)
//{
//	if (IsFull()) return false;		// 队列已满
//	int pos = m_rear;				// 插入的位置
//	m_rear = (m_rear + 1) % (LEN + 1);	// 移动指向尾元素
//	m_queue[pos] = val;
//	return true;
//}
//
//template<typename _Ty, int LEN>
//_Ty LoopQueue<_Ty, LEN>::front()
//{
//	return m_queue[m_front];		// 返回数组首元素
//}
//
//template<typename _Ty, int LEN>
//bool LoopQueue<_Ty, LEN>::pop_front()
//{
//	if (IsEmpty()) return false;
//	m_front = (m_front + 1) % (LEN + 1);	// 将头游标往上移动
//	return true;
//}
//int main(int _args, char* _argc)
//{
//	LoopQueue<int, 5>  loopQueue;
//	if (loopQueue.IsFull())
//		cout << "满" << endl;
//	else
//		cout << "未满" << endl;
//
//	loopQueue.push_back(8);
//	loopQueue.push_back(10);
//
//	loopQueue.pop_front();
//	loopQueue.pop_front();
//
//	if (loopQueue.IsEmpty())
//		cout << "空" << endl;
//	else
//		cout << "非空" << endl;
//
//	LoopQueue<string, 5>  ChQueue;
//	ChQueue.push_back(string("Hell world"));
//	string sTmp = ChQueue.front();
//	cout << sTmp.c_str() << endl;
//
//	//cout << loopQueue.front()<<endl;
//	//loopQueue.pop_front();
//	//cout << loopQueue.front() << endl;
//
//	int nstop; cin >> nstop;
//}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

double Fibonacci(int N)
{
	if (N == 0) return 0;
	if (N == 1) return 1;
	return Fibonacci(N - 1) + Fibonacci(N - 2);
}

const int M = 100;
vector<double> g_lvecFib(M, 0);

double FibonacciOptimization(int N)
{
	if (N == 0) {
		g_lvecFib[0] = 0;
	}
	else if (N == 1) {
		g_lvecFib[1] = 1;
	}
	else {
		g_lvecFib[N] = g_lvecFib[N - 1] + g_lvecFib[N - 2];
	}
	return g_lvecFib[N];
}

string mystery(string s)
{
	int N = s.size();
	if (N <= 1)
		return s;

	string a = s.substr(0, N / 2);
	string b = s.substr(N / 2, N);
	return mystery(b) + mystery(a);
}

int main()
{
	auto temp = gcd(3, 10);

	return 0;
}
