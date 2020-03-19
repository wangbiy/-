#if 0
//����һ������ɾ��������k�����
Node* FindkToTail(Node* head, int k)
{
	Node* front = head;
	Node* back = head;
	for (int i = 0; i < k;++i)
	{
		if (front == nullptr)
			return nullptr;
		front = front->next;
	}
	while (front != nullptr)
	{
		front = front->next;
		back = back->front;
	}
	return back;
}
//������������У�ɾ�����������ظ��Ľ�㣬������һ���ظ���
Node* remove(Node* head)
{
	Node* fackNode = new Node;
	fackNode->next = head;
	Node* pre = fackNode;
	Node* p1 = head;
	Node* p2 = head->next;
	while (p2 != nullptr)
	{
		if (p1->val != p2->val)
		{
			pre = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != nullptr && p1->val == p2->val)
			{
				p2 = p2->next;
			}
			pre->next = p2;
			p1 = p2;
			if(p2 != nullptr)
				p2 = p2->next;
		}
	}
	return fackNode->next;
}
//����һ���ظ�Ԫ��
Node* remove(Node* head)
{
	Node* p1 = head;
	Node* p2 = head->next;
	while (p2 != nullptr )
	{
		if (p1->val != p2->val)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != nullptr && p1->val == p2->val)
			{
				p2 = p2->next;
			}
			p1->next = p2;
			p1 = p2;
			if (p2 != nullptr)
				p2 = p2->next;
		}
	}
	return head;
}
//�����������ɾ���ظ��Ľ�㣬����һ���ظ���
Node* remove(Node* head)
{
	if (head == nullptr)
		return nullptr;
	unordered_map<int, int> hashTable;
	hashTable[head->val] = 1;
	Node* pre = head;
	Node* p = head->next;
	while (p != nullptr)
	{
		if (hashTable.count(p->val))
			pre->next = p->next;
		else
		{
			hashTable[p->val] = 1;
			pre = p;
		}
		p = p->next;
	}
	return head;
}
//�������������ҹ������
int GetLength(Node* head)
{
	int len = 0;
	Node* cur = head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
Node* common(Node* p1, Node* p2)
{
	Node* longer = p1;
	Node* shorter = p2;
	int len1 = GetLength(p1);
	int len2 = Getlength(p2);
	int diff = len1 - len2;
	if (len2 > len1)
	{
		longer = p2;
		shorter = p1;
		diff = len2 - len1;
	}
	for (int i = 0; i < diff; ++i)
	{
		longer = longer->next;
	}
	while (shorter && longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}
//����һ��������������ʼ�뻷�ĵ�һ����㣬��������޻������ؿ�
Node* hasycle(Node* head)
{
	//��ȷ���л�
	Node* fast = head;
	Node* slow = head;
	if (head == nullptr)
		return nullptr;
	do{
		fast = fast->next;
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
		if (fast == nullptr)
			retur nullptr;
		slow = slow->next;
	} while (fast != back);
	Node* p1 = head;
	Node* p2 = slow;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
//��������ĸ�ֵ
Node* copy(Node* head)
{
	Node* cur = head;
	while (cur != nullptr)
	{
		Node* node = new Node(cur->val);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	//����random����
	cur = head;
	while (cur != nullptr && cur->next != nullptr)
	{
		if (cur->random == nullptr)
		{
			cur->next->random = nullptr;
		}
		else
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//��������������
	cur = head;
	Node* pNewNode = head->next;
	while (cur != nullptr && cur->next != nullptr)
	{
		Node* node = cur->next;
		cur->next = node->next;
		if (node->next != nullptr)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return pNewNode;
}
#endif
//�������Ĳ���
#include <iostream>
using namespace std;
//�������Ĺ���
struct TreeNode
{
	TreeNode* _pLeft;
	TreeNode* _pRight;
	char _val;
	TreeNode(char val)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _val(val)
	{}
};
TreeNode* _CreateTree(char* arr, int size, int* index)
{
	TreeNode* pRoot = nullptr;
	if (*index < size && arr[*index] != '#')
	{
		pRoot = new TreeNode(arr[*index]);//�ȹ�������
		(*index)++;
		pRoot->_pLeft = _CreateTree(arr, size, index);
		(*index)++;
		pRoot->_pRight = _CreateTree(arr, size, index);
	}
	return pRoot;
}
TreeNode* CreateTree(char* arr, int size)
{
	int index = 0;
	return _CreateTree(arr, size, &index);
}
//�������Ŀ���
TreeNode* CopyTree(TreeNode* pRoot)
{
	TreeNode* pNewNode = nullptr;
	if (pRoot)
	{
		pNewNode = new TreeNode(pRoot->_val);
		pNewNode->_pLeft = CopyTree(pRoot->_pLeft);
		pNewNode->_pRight = CopyTree(pRoot->_pRight);
	}
	return pNewNode;
}
//������������
void Destroy(TreeNode** pRoot)
{
	if (*pRoot)
	{
		Destroy(&(*pRoot)->_pRight);//������������
		Destroy(&(*pRoot)->_pLeft);
		free(*pRoot);
		*pRoot = nullptr;
	}
}
//�����������������ݹ����
void preorder(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	cout << pRoot->_val << " ";
	preorder(pRoot->_pLeft);
	preorder(pRoot->_pRight);
}
void inorder(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	inorder(pRoot->_pLeft);
	cout << pRoot->_val << " ";
	inorder(pRoot->_pRight);
}
void postorder(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	postorder(pRoot->_pLeft);
	postorder(pRoot->_pRight);
	cout << pRoot->_val << " ";
}
//�����������ǵݹ����
#include <stack>
void preorderNOR(TreeNode* pRoot)
{
	TreeNode* pCur = pRoot;
	stack<TreeNode*> s;
	while (pCur != nullptr && !s.empty())
	{
		while (pCur != nullptr)
		{
			cout << pCur->_val << " ";
			s.push(pCur);
			pCur = pCur->_pLeft;
		}
		TreeNode* top = s.top();
		s.pop();
		pCur = top->_pRight;
	}
}
void inorderNOR(TreeNode* pRoot)
{
	TreeNode* pCur = pRoot;
	stack<TreeNode*> s;
	while (pCur != nullptr && !s.empty())
	{
		while (pCur != nullptr)
		{
			s.push(pCur);
			pCur = pCur->_pLeft;
		}
		TreeNode* top = s.top();
		cout << top->_val << " ";
		s.pop();
		pCur = top->_pRight;
	}
}
void postorderNOR(TreeNode* pRoot)
{
	TreeNode* pCur = pRoot;
	TreeNode* last = nullptr;
	stack<TreeNode*> s;
	while (pCur != nullptr && !s.empty())
	{
		while (pCur != nullptr)
		{
			s.push(pCur);
			pCur = pCur->_pLeft;
		}
		TreeNode* top = s.top();
		if (top->_pRight == nullptr || top->_pRight == last)
		{
			cout << top->_val << " ";
			s.pop();
			last = top;
		}
		else
		{
			pCur = top->_pRight;
		}
	}
}
//�������
#include <queue>
void levelorder(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	queue<TreeNode*> q;
	q.push(pRoot);
	while (!q.empty())
	{
		TreeNode* front = q.front();
		q.pop();
		cout << front->_val << " ";
		if (front->_pLeft)
			q.push(front->_pLeft);
		if (front->_pRight)
			q.push(front->_pRight);
	}
}
//��ȡ�������нڵ�ĸ�������1
int GetCount1(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = GetCount1(pRoot->_pLeft);
	int right = GetCount1(pRoot->_pRight);
	return left + right + 1;
}
//��ȡ�������нڵ�ĸ�������2
int _GetCount2(TreeNode* pRoot, int* count)
{
	if (pRoot == nullptr)
		return 0;
	else
	{
		(*count)++;
		_GetCount2(pRoot->_pLeft,count);
		_GetCount2(pRoot->_pRight,count);
	}
	return *count;
}
int GetCount2(TreeNode* pRoot)
{
	int count = 0;
	return _GetCount2(pRoot, &count);
}
int main()
{
	char* str = "ABD##E#H##CF##G##";
	TreeNode* a = CreateTree(str, strlen(str));
	cout << "�����������ɹ�" << endl;
	TreeNode* pNewNode = CopyTree(a);
	cout << "�����������ɹ�" << endl;
	preorder(a);
	cout << endl;
	inorder(a);
	cout << endl;
	postorder(a);
	cout << endl;
	preorderNOR(a);
	cout << endl;
	inorderNOR(a);
	cout << endl;
	postorderNOR(a);
	cout << endl;
	levelorder(a);
	cout << endl;
	int count = GetCount1(a);
	cout << "������Ϊ:" << count << endl;
	count = GetCount2(a);
	cout << "������Ϊ:" << count << endl;
	return 0;
}