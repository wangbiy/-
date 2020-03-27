#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
//����һ���������� nums ��һ��Ŀ��ֵ target��
//�����ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±�
vector<int> twonum(vector<int>& nums, int target)
{
	vector<int> arr(2);//�����±�
	map<int, int> m;//ͳ��ÿһ��Ԫ���Ƿ���֣���ΪԪ��:��Ӧ�±���ʽ�ļ�ֵ��
	for (int i = 0; i < nums.size(); ++i)
	{
		if (m.count(target - nums[i])>0)//˵����m�д���keyΪ����֮һ��Ԫ��
		{
			arr[0] = m[target - nums[i]];
			arr[1] = i;
			break;
		}
		//�������m�в�����
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