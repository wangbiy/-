#if 0
//key��int���͵ģ�value��string���͵ģ���map��ɾ��keyΪż����
#include <iostream>
using namespace std;
#include <map>
int main()
{
	map<int, string> m{ { 1, "apple" }, { 2, "banana" }, { 3, "orange" } };
	map<int, string>::iterator it;
	for (it = m.begin(); it != m.end();)
	{
		if (it->first % 2 == 0)//ż��
		{
			m.erase(it++);//���ֵ�����ʧЧ���⣬���Ҫerase(it++)
		}
		else//����it�����߼���
			it++;
	}
	return 0;
}
#endif
//�����ַ���A�ַ����е��ַ�ͨ���������Եõ�B�ַ������������ַ���
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
		a[A[i] - 'a']++;//����A��ϣ�б���ÿ���ַ����ֵ�λ�ü�����
		b[B[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (a[i] != b[i])
			return false;//˵�������������ַ����ֵĴ�������λ�ò�ͬ
	}
	if (A == B)//��ȫ��ͬ���������������һ�����ַ����е��ַ����ִ��������μ��������ϣ����־ͷ���true��
		//��һ�־��ǲ����������������false
	{
		for (int i = 0; i < 26; ++i)
		{
			if (a[i]>1)
				return true;
		}
		return false;
	}
	else//�����ַ�������ͬ����A����B�ַ�������ͬ�Ĳ��ֵ��±걣����temp�У��������2���ַ���ͬ������false
	{
		vector<int> tmp;
		for (int i = 0; i < A.size(); ++i)
		{
			if (A[i] != B[i])
			{
				tmp.push_back(i);
			}
		}
		if (tmp.size() != 2)//û�а취����
			return false;
		return true;
	}
}
//������������С�ڵ���Ŀ��ֵ�Ķ��������ӶȲ��ܳ���O(n)
#include <algorithm>
int twoSum5(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return target >= 2 * nums[0] ? 1 : 0;
	sort(nums.begin(), nums.end());//��������������
	int count = 0;
	int i = 0;
	int j = nums.size() - 1;
	while (i < j)
	{
		if (nums[i] + nums[j] <= target)//���i�±��j�±��Ԫ�ط��ϣ����������Ѿ�������ôi��j�Ķ�����	
		{
			count += j - i;
			i++;
		}
		else//������
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
