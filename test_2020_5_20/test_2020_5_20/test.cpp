#include <iostream>
using namespace std;
#include <string>
//��֤�����ַ���������һ���ǿ��ַ��� s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����
bool Palindrome(string s, int i, int j)//�жϻ���
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
		if (s[i] != s[j])//���ɾ��i���ڵ�Ԫ�أ���ֻ��Ҫ�жϴ�i+1��j�Ƿ��ǻ��Ĵ������ɾ��j���ڵ�Ԫ�أ���ֻ��Ҫ�жϴ�i��j-1�Ƿ��ǻ��Ĵ�
			return Palindrome(s, i + 1, j) || Palindrome(s, i, j - 1);
	}
	return true;
}
int main()
{
	string s = "abca";
	if (validPalindrome(s))
		cout << ":��" << endl;
	else
		cout << ":(" << endl;
	return 0;
}