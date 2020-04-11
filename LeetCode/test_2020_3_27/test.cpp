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
int main()
{
	vector<int> nums{ 2, 3, 1, 4, 5 };
	int target = 6;
	vector<int> result = twonum(nums, target);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	return 0;
}