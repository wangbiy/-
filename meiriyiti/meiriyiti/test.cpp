#include <iostream>
using namespace std;
#include <vector>
#if 0
//斐波那契凤尾，即输出第n个斐波那契数，如果超过6位数，就返回后六位即可
int main()
{
	vector<int> fib(1000001);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 1000001; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= 1000000;
	}
	int n;
	while (cin >> n)
	{
		if (n < 29)
			printf("%d\n", fib[n]);
		else
			printf("%06d\n", fib[n]);
	}
	return 0;
}
#endif
#if 0
//求出斐波那契数列中某一段的和
#define MAXSIZE 83
vector<long long> fibonacci(vector<long long>& arr)
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < MAXSIZE; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr;
}
//求某一段的和
long long Sum(vector<long long>& arr, int from, int to)
{
	return arr[to + 1] - arr[from];
}
int main()
{
	int from, to;
	vector<long long> arr(MAXSIZE);
	vector<long long> ret= fibonacci(arr);
	while (cin >> from >> to)
	{
		long long result = Sum(ret, from, to);
		cout << result << endl;
	}
	return 0;
}
#endif
#if 0
//一种消息接收并打印的结构设计
//也就是整数1到N，不一定按照顺序输出，如果上次打印的数是i，那么当i+1出现
//时，打印i+1及其之后接收过的并且连续的所有数，直到1到N全部接收并打印完
//例如输入两行，第一行是9，第二行是9个数字，即2 1 4 5 7 3 9 8 6
//输出 11 21 33 43 53 66 76 86 96
template<class T>
struct greater
{
	bool operator()(T& a, T& b)
	{
		return a >= b;
	}
};
#include <queue>
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	priority_queue<int, vector<int>, greater<int>> q;
	int min = 1;
	int k = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		q.push(arr[i]);
		if (arr[i] == min)//如果等于min，说明此时是符合要求的，是连续的
		{
			while (q.top() == min)
			{
				cout << k++ << " " << arr[i] << endl;
				min++;
				q.pop();
			}
		}
	}
	return 0;
}
#endif
#if 0
//养兔子问题
//也就是一开始有1个兔子，成熟期是1天，成熟兔子一天生一个兔子，n天后有多少个兔子
//1<=n<=90
#define MAXSIZE 90
int main()
{
	int n;
	vector<long long> arr(MAXSIZE);
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < MAXSIZE; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	while (cin >> n)
	{
		cout << arr[n - 1] << endl;
	}
	return 0;
}
#endif
#if 0
//在s字符串中t字符串一共出现了多少次
#include <string>
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int result = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)
		{
			result++;
			pos += t.size();
		}
		cout << result << endl;
	}
}
#endif
#if 0
//即在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//给一段时间区间，请计算总收益有多少
//判断是否是闰年
int leap_year(int year)//如果是闰年，返回1，否则返回0
{
	return ((year % 4 != 0 && year % 100 == 0) || year % 400 == 0);
}
//2 3 5 7 11月是素数
//1 3 5 7 8 10 12月是31天
int profit(int year)
{
	return 2 * 31 + 1 * 28 + leap_year(year) + 1 * 31 + 2 * 30 + 1 * 31 + 2 * 30 + 1 * 31 + 2 * 31 + 2 * 30 + 2 * 31 + 1 * 30 + 2 * 31;
}
bool isprime(int month)//判断是否是素数月
{
	return month == 2 || month == 3 || month == 5 || month == 7 || month == 11;
}
//求某一天是这一年的第几天，算出总收益
int profitOfthisyear(int year, int month, int day)
{
	if (!isprime(month))//判断这个月是不是素数月
		day *= 2;
	while (--month)
	{
		switch (month)
		{
			//既不是素数又是31天的月份
			case 1:
			case 8:
			case 10:
			case 12:
				day += 62;
				break;
			//既不是素数又是30天的月份
			case 4:
			case 6:
			case 9:
				day += 60;
				break;
			//既是素数又是31天的月份
			case 3:
			case 5:
			case 7:
				day += 31;
				break;
			//既是素数又是30天的月份
			case 11:
				day += 30;
				break;
			case 2:
				day += 28 + leap_year(year);
				break;
			default:
				;
		}
	}
	return day;
}
int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int sum = 0;//总收益
		sum += profit(year1) - profitOfthisyear(year1, month1, day1);//计算出在year1这年中year1，month1，day1这一天之后的总收入
		sum += profitOfthisyear(year2, month2, day2);//再加上从year2这年开始到year2,month2,day2这一天的收益
		//这两个相加之后就得到了从year1,month1,day1到year2,month2,day2的收益
		if (year1 == year2)//如果是在一年内
			sum -= profit(year1);
		for (int i = year1 + 1; i < year2; ++i)
		{
			//计算中间有多少年就在加几年的收益
			sum += profit(i);
		}
		cout << sum << endl;
	}
	return 0;
}
#endif
#if 0
//分解因数
//给定的正整数a，分解成若干个素数的乘积，
//即 a = a1 × a2 × a3 × ... × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ ...≤ an,
//其中a1、a2、...、an均为素数,先给出一个整数a，请输出分解后的因子;
int main()
{
	int n;
	while (cin >> n)
	{
		printf("%d = ", n);
		for (int i = 2; i < sqrt(n); ++i)
		{
			while (n%i == 0 && n != i)//用n反复除从2开始的同一个数，直到除不尽
			{
				printf("%d* ", i);
				n /= i;
			}
		}
		printf("%d\n", n);//最后一个质因数
	}
	return 0;
}
#endif
//将字符串前面的若干个字符移到字符串的尾部
//方法一、暴力解决，将字符一个一个移到末尾
//先定义一个将一个字符移到末尾的函数
void removech(string& s, int n)
{
	char ch = s[0];
	for (int i = 1; i < n; ++i)
	{
		s[i - 1] = s[i];//全部向前移一个位置，再将ch放到最后即可
	}
	s[n - 1] = ch;
}
//然后将这个函数调用要移动的字符的个数次即可
void remove(string& s,int size,int m)//移动m个字符
{
	while (m--)
	{
		removech(s, size);
	}
}
//但是蛮力法的时间复杂度是O(mn),因此我们要使用一种降低时间复杂度的方法
//可以将字符串分为要移动的字符和不用移动的字符两部分，先将两部分分别反转即可得到，然后将整个字符串反转
void reverseString(string& s, int start,int end)
{
	while (start < end)
	{
		char t = s[start];
		s[start] = s[end];
		s[end] = t;
		start++;
		end--;
	}
}
void reverse(string& s, int n,int m)//要移动m位
{
	m %= n;//防止出现m>n的情况
	reverseString(s, 0, m - 1);//先将两部分分别反转
	reverseString(s, m, n - 1);
	reverseString(s, 0, n - 1);//再整体反转
}
int main()
{
	string s = "abcdefg";
	//remove(s, s.size(), 3);
	reverse(s, s.size(), 3);
	return 0;
}
