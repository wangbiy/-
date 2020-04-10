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
#if 0
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
#endif
#if 0
//单词反转问题
#include <string>
void reverse(string& s, int start, int end)//整体反转
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
void reversestring(string& s, int n)
{
	//先整体反转
	reverse(s, 0, n - 1);
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == ' ')
		{
			end = i;
			reverse(s, start, end);
			start = end + 1;
		}
	}
}
int main()
{
	string s = "I am a student";
	reversestring(s, s.size());
}
#endif
#if 0
//数据库连接池问题
//也就是如果遇到一个连接就创建一个连接，得到最后的最多连接数
//例如输入  6 A connect、A disconnect、B connect、C connect、B disconnect、C disconnect
//输出2
//就是求最多需要连接数保证所有的都能执行
#include <set>
#include <string>
int main()
{
	int n;
	while (cin >> n)
	{
		string id, mes;
		set<string> pool;
		int MaxSize = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> id >> mes;
			if (mes == "connect")
				pool.insert(id);
			else if (mes == "disconnect")
				pool.erase(id);
			int size = pool.size();
			MaxSize = MaxSize>size ? MaxSize : size;
		}
		cout << MaxSize << endl;
	}
	return 0;
}
#endif
#if 0
//实现mkdir -p功能，就是如果出现类似/usr/local /usr/local/test,就不用再创建第二遍/usr/local了
//如果出现两个字符串相同，也不用再创建一次，如果不同且不是子串的关系，才能创建
#include <vector>
#include <string>
#include <algorithm>
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> ret(n);//保存每个字符串
		vector<bool> flag(n, true);//表示两个字符串中前面的那一个能不能被创建
		for (int i = 0; i < n; ++i)
		{
			cin >> ret[i];
		}
		sort(ret.begin(), ret.end());//将类似的字符串放在一起
		for (int i = 0; i < ret.size() - 1; ++i)//遍历字符串数组进行判断
		{
			if (ret[i] == ret[i + 1])//两个字符串相等
				flag[i] = false;
			else if (ret[i].size() < ret[i + 1].size() && ret[i] == ret[i + 1].substr(0, ret[i].size()) && ret[i + 1][ret[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i < ret.size(); ++i)
		{
			if (flag[i] == true)
				cout << "mkdir -p " << ret[i] << endl;
		}
		cout << endl;
	}
	return 0;
}
#endif
//字符串的包含
//也就是判断a字符串中是否包含B字符串
#if 0
//方法1.暴力法
#include <string>
bool contain1(string a, string b)
{
	for (int i = 0; i < b.size(); ++i)
	{
		int j;
		for (j = 0; j < a.size() && a[j] != b[i]; ++j)
			;//一直找看a中有没有和b当前字符相同的
		//找到这说明在a中找到和b中字符相同的了
		if (j>a.size())
			return false;
	}
	//这里说明包含
	return true;
}
#endif
#if 0
//但是暴力法的时间复杂度是O(a的长度*b的长度），时间复杂度很大，因此我们必须要进行优化
//可以分别对两个字符串进行排序，然后进行轮询
#include <algorithm>
bool contain2(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0, j = 0; j < b.size();)
	{
		while (i < a.size() && a[i] < b[j])//要是a当前的字符小于b当前的字符
			i++;
		if (i>a.size() && a[i]>b[j])//说明在a中一定不存在b
			return false;
		j++;
	}
	return true;
}
int main()
{
	string a = "abcabc";
	string b = "abc";
	bool flag = contain2(a, b);

	return 0;
}
#endif
#include <string>
#include <algorithm>
//最长公共子序列
//也就是字符串换1：abcdaf,字符串2：acbcf:此时的最长公共子序列就是abcf
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	//先将第0行和第0列都初始化为0
	for (int i = 0; i < n + 1; ++i)
		dp[i][0] = 0;
	for (int i = 0; i < m + 1; ++i)
		dp[0][i] = 0;
	//然后进行实现
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			if (s1[j - 1] == s2[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	//输出长度
	cout << dp[n][m] << endl;
	return 0;
}
