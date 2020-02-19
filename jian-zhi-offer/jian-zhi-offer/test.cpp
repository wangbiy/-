#include <iostream>
using namespace std;
#include <vector>
//1.��ά�����еĲ���
bool Find(int target, vector<vector<int>> array)
{
	int row = array.size();
	int col = array[0].size();
	int left = 0;
	int right = col - 1;
	while (left < row && right >= 0)
	{
		if (target == array[left][right])
			return true;
		else if (target < array[left][right])
		{
			right--;
		}
		else
			left++;
	}
	return false;
}
//2.��һ���ַ����е�ÿ���ո��滻�ɡ�%20��
void replaceSpace(char *str, int length)
{
	if (str == nullptr)
		return;
	int count = 0;
	int originlen = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		originlen++;
		if (str[i] == ' ')
			count++;
	}
	int newlen = originlen + count * 2;
	if (newlen + 1 > length)
		return;
	int ptr1 = originlen;;
	int ptr2 = newlen;
	while (ptr1 >= 0 && ptr2 >= ptr1)
	{
		if (str[ptr1] == ' ')
		{
			str[ptr2--] = '0';
			str[ptr2--] = '2';
			str[ptr2--] = '%';
		}
		else
		{
			str[ptr2--] = str[ptr1];
		}
		ptr1--;
	}
}
//�������β��ͷ��˳���ӡArrayList
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL) 
	{}
};
#include <stack>
vector<int> printListFromTailToHead(ListNode* head)
{
	vector<int> ArrayList;
	stack<int> s;
	ListNode* pCur = head;
	while (pCur)
	{
		s.push(pCur->val);
		pCur = pCur->next;
	}
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		ArrayList.push_back(s.top());
		s.pop();
	}
	return ArrayList;
}
int main()
{
	vector<vector<int>> array{{ 1, 2, 3 } ,{4, 5, 6} , {7, 8, 9}};
	if (Find(3, array))
		cout << "�����ҵ�" << endl;
	else
		cout << "�Ҳ���" << endl;

	char* str = "we are happy";
	replaceSpace(str, strlen(str));
	cout << str << endl;
	return 0;
}