#include <iostream>
using namespace std;
//平方数之和：给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b ^2 = c
bool judgeSquareSum(int c)
{
	if (c < 0)
		return false;
	long begin = 0;
	long end = (long)sqrt(c);
	while (begin <= end)
	{
		int sum = begin*begin + end*end;
		if (sum == c)
			return true;
		else if (sum < c)
			begin++;
		else
			end--;
	}
	return false;
}
//反转字符串中的元音字母，例如leetcode反转后为leotcede
bool isorigin(char ch)//判断是否是元音字符
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
		|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		return true;
	else
		return false;
}
#include <string>
string reverseVowels(string s)
{
	if (s.empty())
		return s;
	int begin = 0;
	int end = s.size();
	while (begin < end)
	{
		if (!isorigin(s[begin]))
		{
			begin++;
			continue;
		}
		if (!isorigin(s[end]))
		{
			end--;
			continue;
		}
		swap(s[begin++], s[end--]);
	}
	return s;
}
int main()
{
	int c = 5;
	if (judgeSquareSum(c) == true)
		cout << "有" << endl;
	else
		cout << "没有" << endl;

	string s = "leetcode";
	string str = reverseVowels(s);
	cout << str << endl;
	return 0;
}