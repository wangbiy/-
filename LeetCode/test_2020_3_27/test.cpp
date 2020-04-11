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
int main()
{
	vector<int> nums{ 2, 3, 1, 4, 5 };
	int target = 6;
	vector<int> result = twonum(nums, target);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	return 0;
}