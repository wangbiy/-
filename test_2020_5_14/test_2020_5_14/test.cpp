#include <iostream>
using namespace std;
#include <vector>
//��������� Two Sum���������������ҳ���������ʹ���ǵĺ�Ϊ target
vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> result;
	if (numbers.empty())
		return result;
	int begin = 0;
	int end = numbers.size() - 1;
	while (begin < end)
	{
		int sum = numbers[begin] + numbers[end];
		if (sum == target)
		{
			result.push_back(begin + 1);
			result.push_back(end + 1);
			return result;
		}
		else if (sum < target)
		{
			begin++;
		}
		else
			end--;
	}
	return result;
}
//������ֻ����һ�ε����������������������Σ��ҵ��Ǹ���
int singleNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		result ^= nums[i];
	}
	return result;
}
int main()
{
	vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> result = twoSum(numbers, 7);
	for (auto e : result)
		cout << e << " ";
	cout << endl;

	vector<int> nums{ 1, 3, 1, 2, 4, 2, 4 };
	int ret = singleNumber(nums);
	cout << ret << endl;
	return 0;
}