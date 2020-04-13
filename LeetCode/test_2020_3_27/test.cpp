#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
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
//合并k个有序链表
#if 0
//方法1，使用优先级队列，每次将每个链表的第一个结点存入优先级队列，然后弹出，存入结果链表
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
//方法2，先实现两两合并链表，然后实现
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
//无重复子串的最大长度
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
//最大回文长度
//使用从回文中间向左右推进的方法来实现回文串，然后在这些回文串中找最大的即可
#include <string>
string searchfromCenter(string s, int left, int right)
{
	while (left >= 0 && right < s.size())
	{
		if (s[left] == s[right])//继续推进
		{
			left--;
			right++;
		}
		else
			break;
	}
	return s.substr(left + 1, right - left - 1);//截取left和right中间的字符串，不包含left和right，这就是所得到的回文串
}
string longestPalindrome(string s)
{
	if (s.size() == 0 || s.size() == 1)
		return s;
	int maxLen = 1;//一开始最大回文串的长度是1，因为是单个字符表示回文串
	string result = s.substr(0, 1);
	for (int i = 0; i < s.size() - 1; ++i)
	{
		string s1 = searchfromCenter(s, i, i);//表示回文中间是一个字符的情况
		string s2 = searchfromCenter(s, i, i + 1);//表示回文中间是两个字符间隙的情况
		string s3 = s1.size()>s2.size() ? s1 : s2;
		if (maxLen < s3.size())
		{
			maxLen = s3.size();
			result = s3;
		}
	}
	return result;
}
//Z字形变换
string convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	vector<string> rows(min(numRows, int(s.size())));
	int cur = 0;//当前所在字符的位置，用来看什么时候对折
	bool goingdown = false;//用来表示是否已经到了要对折的点
	for (char e : s)
	{
		rows[cur] += e;
		if (cur == 0 || cur == numRows - 1)//开始对折
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