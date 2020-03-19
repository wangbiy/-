#if 0
//key是int类型的，value是string类型的，从map中删除key为偶数的
#include <iostream>
using namespace std;
#include <map>
int main()
{
	map<int, string> m{ { 1, "apple" }, { 2, "banana" }, { 3, "orange" } };
	map<int, string>::iterator it;
	for (it = m.begin(); it != m.end();)
	{
		if (it->first % 2 == 0)//偶数
		{
			m.erase(it++);//出现迭代器失效问题，因此要erase(it++)
		}
		else//否则it往后走即可
			it++;
	}
	return 0;
}
#endif
//亲密字符串A字符串中的字符通过交换可以得到B字符串就是亲密字符串
#include <vector>
#include <string>
#include <iostream>
using namespace std;
bool buddystrings(string A, string B)
{
	if (A.size() != B.size())
		return false;
	int a[26] = { 0 };
	int b[26] = { 0 };
	for (int i = 0; i < A.size(); ++i)
	{
		a[A[i] - 'a']++;//存在A哈希中保存每个字符出现的位置及次数
		b[B[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (a[i] != b[i])
			return false;//说明两者所含的字符出现的次数或者位置不同
	}
	if (A == B)//完全相同，考虑两种情况，一种是字符串中的字符出现次数在两次及两次以上，这种就返回true，
		//另一种就是不是这种情况，返回false
	{
		for (int i = 0; i < 26; ++i)
		{
			if (a[i]>1)
				return true;
		}
		return false;
	}
	else//两个字符串不相同，将A中与B字符串不相同的部分的下标保存在temp中，如果不是2个字符不同，返回false
	{
		vector<int> tmp;
		for (int i = 0; i < A.size(); ++i)
		{
			if (A[i] != B[i])
			{
				tmp.push_back(i);
			}
		}
		if (tmp.size() != 2)//没有办法交换
			return false;
		return true;
	}
}
//数组两个数和小于等于目标值的对数，复杂度不能超过O(n)
#include <algorithm>
int twoSum5(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return target >= 2 * nums[0] ? 1 : 0;
	sort(nums.begin(), nums.end());//排序按照升序排序
	int count = 0;
	int i = 0;
	int j = nums.size() - 1;
	while (i < j)
	{
		if (nums[i] + nums[j] <= target)//如果i下标和j下标的元素符合，由于数组已经排序，那么i到j的都符合	
		{
			count += j - i;
			i++;
		}
		else//不符合
			j--;
	}
	return count;
}
int main()
{
	string A = "aa";
	string B = "aa";
	bool flag=buddystrings(A, B);
	if (flag == true)
		cout << ":)" << endl;
	else
		cout << ":(" << endl;
	vector<int> nums{ 2, 7, 11, 15 };
	int count = twoSum5(nums, 24);
	cout << count << endl;
	return 0;
}
