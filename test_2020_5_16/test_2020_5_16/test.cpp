#include <iostream>
using namespace std;
//ƽ����֮�ͣ�����һ���Ǹ����� c ����Ҫ�ж��Ƿ������������ a �� b��ʹ�� a^2 + b ^2 = c
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
//��ת�ַ����е�Ԫ����ĸ������leetcode��ת��Ϊleotcede
bool isorigin(char ch)//�ж��Ƿ���Ԫ���ַ�
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
		cout << "��" << endl;
	else
		cout << "û��" << endl;

	string s = "leetcode";
	string str = reverseVowels(s);
	cout << str << endl;
	return 0;
}