#include <iostream>
using namespace std;
//У�б�����ż�
#if 0
//1.�³���
#include <set>
#include <string>
int main()
{
	string str;
	set<string> s;
	while (cin >> str)
	{
		s.insert(str);//ȥ��
	}
	cout << s.size() << endl;
	return 0;
}
#endif
#if 0
//2.��ƻ��
#include <vector>
#include <math.h>
int avg(vector<int> arr)
{
	int average = 0;//ƽ����
	int sum = 0;//ƻ������
	int n = arr.size();//��ţ��
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];//ͳ��ƻ������
	}
	average = sum / n;//ƽ��ֵ
	if (sum % n != 0)//˵������ƽ�֣�����-1
		return -1;
	for (int i = 0; i < n; ++i)
	{
		int ret = abs(arr[i] - average);//�������ǰ��ţӵ�е�ƻ������ƽ��ֵ�Ĳ�ֵ����ֵ�������������2��˵�����޷��ƶ���ֱ�ӷ���-1
		if (ret % 2 != 0)
			return -1;
	}
	//�ߵ�����˵������ƽ�ֲ�����ţ��ƻ������ÿ���ƶ�2��
	int count = 0;//ͳ�ƴ���
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>average)//ֻ�б�ƽ��ֵ�����ţ��ƻ�����ſ����ƶ�
			count += (arr[i] - average) / 2;
	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	vector<int> num(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	int count = avg(num);
	cout << count << endl;
	return 0;
}
#endif
#if 0
//3.�Ǽʴ�Խ
#include <math.h>
int main(){
	long h, i;
	while (cin >> h){
		long s = sqrt(h);
		for (i = s; i + i*i > h; --i)
		{}
		cout << i << endl;
	}
	return 0;
}
#endif
//4.�ر�ͼ
#include <string>
int main(){
	string str;//ԭ�ַ���
	while (cin >> str)
	{
		string _str;//������
		cin >> _str;
		int i = 0;//����ԭ�ַ���
		int j = 0;//����������
		while (i < str.size())
		{
			if (str[i++] == _str[j])
				j++;
		}
		if (j == _str.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}