#include <iostream>
using namespace std;
//校招编程入门级
#if 0
//1.下厨房
#include <set>
#include <string>
int main()
{
	string str;
	set<string> s;
	while (cin >> str)
	{
		s.insert(str);//去重
	}
	cout << s.size() << endl;
	return 0;
}
#endif
#if 0
//2.分苹果
#include <vector>
#include <math.h>
int avg(vector<int> arr)
{
	int average = 0;//平均数
	int sum = 0;//苹果总数
	int n = arr.size();//奶牛数
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];//统计苹果总数
	}
	average = sum / n;//平均值
	if (sum % n != 0)//说明不能平分，返回-1
		return -1;
	for (int i = 0; i < n; ++i)
	{
		int ret = abs(arr[i] - average);//计算出当前奶牛拥有的苹果树与平均值的差值绝对值，如果不能整除2，说明就无法移动，直接返回-1
		if (ret % 2 != 0)
			return -1;
	}
	//走到这里说明可以平分并且奶牛的苹果可以每次移动2个
	int count = 0;//统计次数
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>average)//只有比平均值大的奶牛的苹果数才可以移动
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
//3.星际穿越
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
//4.藏宝图
#include <string>
int main(){
	string str;//原字符串
	while (cin >> str)
	{
		string _str;//子序列
		cin >> _str;
		int i = 0;//遍历原字符串
		int j = 0;//遍历子序列
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