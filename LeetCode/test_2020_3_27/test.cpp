#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
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
//�ϲ�k����������
#if 0
//����1��ʹ�����ȼ����У�ÿ�ν�ÿ������ĵ�һ�����������ȼ����У�Ȼ�󵯳�������������
ListNode* mergeKLists(vector<listNode*>& lists)
{
	priority_queue<ListNode*, vector<ListNode*>, com> q;
	for (auto e : lists)
	{
		if (e)
			q.push(e);
	}
	ListNode result(-1);
	ListNode* h = &result;
	while (!q.empty())
	{
		ListNode* top = q.top();
		q.pop();
		h->next = top;
		h = top;
		if (top->next)
			q.push(top->next);
	}
	return result.next;
}
#endif
#if 0
//����2����ʵ�������ϲ�����Ȼ��ʵ��
ListNode* mergelists(ListNode* head1, ListNode* head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	if (head1->val <= head2->val)
	{
		head1->next = mergelists(head1->next, head2);
		return head1;
	}
	else
	{
		head2 -> next = mergelists(head1, head2->next);
		return head2;
	}
}
ListNode* mergeKlists(vector<ListNode*>& lists)
{
	if (lists.size()==0)
		return nullptr;
	ListNode* head = lists[0];
	for (int i = 1; i < lists.size(); ++i)
	{
		if (lists[i])
			head = mergelists(head, lists[i]);
	}
	return head;
}
#endif
int max(int a, int b)
{
	return a > b ? a : b;
}
//���ظ��Ӵ�����󳤶�
int lengthOfLongestSubstring(string s)
{
	vector<int> table(128, -1);
	int left = -1;
	int right, maxlen = 0;
	for (right = 0; right < s.size(); ++right)
	{
		if (table[s[right]] == -1 || left>table[s[right]])
			table[s[right]] = right;
		else
		{
			maxlen = max(maxlen, right - left - 1);
			left = table[s[right]];
			table[s[right]] = right;
		}
	}
	return max(maxlen, right - left - 1);
}
//�����ĳ���
//ʹ�ôӻ����м��������ƽ��ķ�����ʵ�ֻ��Ĵ���Ȼ������Щ���Ĵ��������ļ���
#include <string>
string searchfromCenter(string s, int left, int right)
{
	while (left >= 0 && right < s.size())
	{
		if (s[left] == s[right])//�����ƽ�
		{
			left--;
			right++;
		}
		else
			break;
	}
	return s.substr(left + 1, right - left - 1);//��ȡleft��right�м���ַ�����������left��right����������õ��Ļ��Ĵ�
}
string longestPalindrome(string s)
{
	if (s.size() == 0 || s.size() == 1)
		return s;
	int maxLen = 1;//һ��ʼ�����Ĵ��ĳ�����1����Ϊ�ǵ����ַ���ʾ���Ĵ�
	string result = s.substr(0, 1);
	for (int i = 0; i < s.size() - 1; ++i)
	{
		string s1 = searchfromCenter(s, i, i);//��ʾ�����м���һ���ַ������
		string s2 = searchfromCenter(s, i, i + 1);//��ʾ�����м��������ַ���϶�����
		string s3 = s1.size()>s2.size() ? s1 : s2;
		if (maxLen < s3.size())
		{
			maxLen = s3.size();
			result = s3;
		}
	}
	return result;
}
//Z���α任
string convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	vector<string> rows(min(numRows, int(s.size())));
	int cur = 0;//��ǰ�����ַ���λ�ã�������ʲôʱ�����
	bool goingdown = false;//������ʾ�Ƿ��Ѿ�����Ҫ���۵ĵ�
	for (char e : s)
	{
		rows[cur] += e;
		if (cur == 0 || cur == numRows - 1)//��ʼ����
		{
			goingdown = !goingdown;
		}
		cur += goingdown ? 1 : -1;
	}
	string result;
	for (string row : rows)
		result += row;
	return result;
}
int main()
{
	vector<int> nums{ 2, 3, 1, 4, 5 };
	int target = 6;
	vector<int> result = twonum(nums, target);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";

	int len = lengthOfLongestSubstring("abcabcabc");
	cout << len << endl;

	string ret = longestPalindrome("babad");

	string str = "LEETCODEISHIRING";
	ret = convert(str, 3);
	cout << ret << endl;
	return 0;
}