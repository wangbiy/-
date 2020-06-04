#include <iostream>
using namespace std;
#include <string>
#include <vector>
//����һ���ַ�����һ���ַ����ֵ䣬�ҵ��ֵ���������ַ�����
//���ַ�������ͨ��ɾ�������ַ�����ĳЩ�ַ����õ�,����𰸲�ֹһ����
//���س�������ֵ�˳����С���ַ���,����𰸲�����,�򷵻ؿ��ַ���
bool isSubstr(string s, string t)//�ж�t�ַ����Ƿ���s��������
{
	int i = 0;//��������s
	int j = 0;//��������t
	while (i<s.size() && j<t.size())
	{
		if (s[i] == t[j])//������t����ַ�������߼����ж�
			j++;
		i++;
	}
	return j == t.size();//���Ƿ����s�ĳ��ȱ�t�ĳ���С��������ͻᵼ��i������s������j��û������t
}
string findLongestWord(string s, vector<string>& d) {
	string result = "";//����ַ���
	for (int i = 0; i<d.size(); ++i)//����d
		//��������Ҫ�ҵ�������У����ÿ��Ҫ��result�ĳ��Ƚ��бȽ�,���ÿ�α��������ַ�����result�ĳ���С���߳�����ͬ����result����ĸ˳��ȱ��������ַ�����ĸ˳��С����Ҫ����ѭ������
	{
		if (result.size()>d[i].size() || (result.size() == d[i].size() && result.compare(d[i])<0))
			continue;
		if (isSubstr(s, d[i]))//�������������Ҫ��
			result = d[i];
	}
	return result;
}
int main()
{
	string s = "abpcplea";
	vector<string> d = { "ale", "apple", "monkey", "plea" };
	string result = findLongestWord(s, d);
	cout << result << endl;
	return 0;
}