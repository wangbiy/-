#include <iostream>
using namespace std;
#include <vector>
//���ֲ��Ҽ������(�������������飩
//���ֲ���
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
//����
//���ҵ�һ��ֵ���ڸ���ֵ�����(ԭʼ�������ظ������)
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
				right = mid - 1;//ǰ���Ҳ�Ǹ���ֵ����right�Ƶ�ǰ�棬����ִ��
		}
	}
	return -1;
}
//�������һ��ֵ���ڸ���ֵ�����
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
		else//�������ֵ��mid���ڵ�ֵ��ȣ����Ǵ�ʱ��ȷ���ǲ������һ����target��ȵ�
		{
			if (mid == n - 1 || nums[mid + 1] != target)
				return mid;
			else
				left = mid + 1;
		}
	}
	return -1;
}
//���ҵ�һ�����ڵ��ڸ���ֵ�����
int BinarySearch3(vector<int>& nums, int n, int target)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if(nums[mid]>=target)//���ڵ���
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
//�������һ��С�ڵ��ڸ���ֵ�����
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
	cout << "7��λ����:" << result << endl;
	result = BinarySearch1(nums, 11, 3);
	cout << "��һ��ֵΪ3��λ��:" << result << endl;
	result = BinarySearch2(nums, 11, 3);
	cout << "���һ��ֵΪ3��λ��:" << result << endl;
	result = BinarySearch3(nums, 11, 4);
	cout << "��һ�����ڵ���4��ֵ��λ��:" << result << endl;
	result = BinarySearch4(nums, 11, 4);
	cout << "���һ��С�ڵ���4��ֵ��λ��:" << result << endl;
	return 0;
}