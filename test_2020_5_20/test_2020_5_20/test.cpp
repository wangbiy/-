#include <iostream>
using namespace std;
#include <string>
//验证回文字符串：给定一个非空字符串 s，最多删除一个字符，判断是否能成为回文字符串。
bool Palindrome(string s, int i, int j)//判断回文
{
	while (i < j)
	{
		if (s[i++] != s[j--])
			return false;
	}
	return true;
}
bool validPalindrome(string s)
{
	for (int i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		if (s[i] != s[j])//如果删除i所在的元素，则只需要判断从i+1到j是否是回文串；如果删除j所在的元素，则只需要判断从i到j-1是否是回文串
			return Palindrome(s, i + 1, j) || Palindrome(s, i, j - 1);
	}
	return true;
}
int main()
{
	string s = "abca";
	if (validPalindrome(s))
		cout << ":）" << endl;
	else
		cout << ":(" << endl;
	return 0;
}