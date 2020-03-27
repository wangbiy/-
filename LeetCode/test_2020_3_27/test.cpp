#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
//给定一个整数数组 nums 和一个目标值 target，
//请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标
vector<int> twonum(vector<int>& nums, int target)
{
	vector<int> arr(2);//保存下标
	map<int, int> m;//统计每一个元素是否出现，存为元素:对应下标形式的键值对
	for (int i = 0; i < nums.size(); ++i)
	{
		if (m.count(target - nums[i])>0)//说明在m中存在key为两数之一的元素
		{
			arr[0] = m[target - nums[i]];
			arr[1] = i;
			break;
		}
		//否则如果m中不存在
		m[nums[i]] = i;
	}
	return arr;
}
int main()
{
	vector<int> nums{ 2, 3, 1, 4, 5 };
	int target = 6;
	vector<int> result = twonum(nums, target);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	return 0;
}