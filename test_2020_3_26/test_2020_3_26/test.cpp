#include <iostream>
using namespace std;
#include <vector>
//二分查找及其变形(数组是排序数组）
//二分查找
int BinarySearch(vector<int>& nums, int n, int target)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid]>target)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
//变形
//查找第一个值等于给定值的情况(原始数组有重复的情况)
int BinarySearch1(vector<int>& nums, int n, int target)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid]>target)
			right = mid - 1;
		else
		{
			if (mid == 0 || nums[mid - 1] != target)
				return mid;
			else
				right = mid - 1;//前面的也是给定值，将right移到前面，继续执行
		}
	}
	return -1;
}
//查找最后一个值等于给定值的情况
int BinarySearch2(vector<int>& nums, int n, int target)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid]>target)
			right = mid - 1;
		else//发现这个值和mid所在的值相等，但是此时不确定是不是最后一个与target相等的
		{
			if (mid == n - 1 || nums[mid + 1] != target)
				return mid;
			else
				left = mid + 1;
		}
	}
	return -1;
}
//查找第一个大于等于给定值的情况
int BinarySearch3(vector<int>& nums, int n, int target)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if(nums[mid]>=target)//大于等于
		{
			if (mid == 0 || nums[mid - 1] < target)
				return mid;
			else
				right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return -1;
}
//查找最后一个小于等于给定值的情况
int BinarySearch4(vector<int>& nums, int n, int target)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (nums[mid]<=target)
		{
			if (mid == n - 1 || nums[mid + 1]>target)
				return mid;
			else
				left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return -1;
}
int main()
{
	vector<int> nums{ 1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8 };
	int result = BinarySearch(nums, 11, 7);
	cout << "7的位置是:" << result << endl;
	result = BinarySearch1(nums, 11, 3);
	cout << "第一个值为3的位置:" << result << endl;
	result = BinarySearch2(nums, 11, 3);
	cout << "最后一个值为3的位置:" << result << endl;
	result = BinarySearch3(nums, 11, 4);
	cout << "第一个大于等于4的值的位置:" << result << endl;
	result = BinarySearch4(nums, 11, 4);
	cout << "最后一个小于等于4的值的位置:" << result << endl;
	return 0;
}