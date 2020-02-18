#include <iostream>
using namespace std;
#include <vector>
//1.二维数组中的查找
bool Find(int target, vector<vector<int>> array)
{
	int row = array.size();
	int col = array[0].size();
	int left = 0;
	int right = col - 1;
	while (left < row && right >= 0)
	{
		if (target == array[left][right])
			return true;
		else if (target < array[left][right])
		{
			right--;
		}
		else
			left++;
	}
	return false;
}
//2.将一个字符串中的每个空格替换成“%20”
void replaceSpace(char *str, int length)
{
	if (str == nullptr)
		return;
	int count = 0;
	int originlen = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		originlen++;
		if (str[i] == ' ')
			count++;
	}
	int newlen = originlen + count * 2;
	if (newlen + 1 > length)
		return;
	int ptr1 = originlen;;
	int ptr2 = newlen;
	while (ptr1 >= 0 && ptr2 >= ptr1)
	{
		if (str[ptr1] == ' ')
		{
			str[ptr2--] = '0';
			str[ptr2--] = '2';
			str[ptr2--] = '%';
		}
		else
		{
			str[ptr2--] = str[ptr1];
		}
		ptr1--;
	}
}
int main()
{
	vector<vector<int>> array{{ 1, 2, 3 } ,{4, 5, 6} , {7, 8, 9}};
	if (Find(3, array))
		cout << "可以找到" << endl;
	else
		cout << "找不到" << endl;

	char* str = "we are happy";
	replaceSpace(str, strlen(str));
	cout << str << endl;
	return 0;
}