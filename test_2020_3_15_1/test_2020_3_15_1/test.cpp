#if 0
//输入一个链表，删除倒数第k个结点
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
//在排序的链表中，删除该链表中重复的结点，不保存一个重复的
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
//保留一个重复元素
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
//非排序的链表删除重复的结点，保留一个重复的
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
//在两个链表中找公共结点
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
//给定一个链表，返回链表开始入环的第一个结点，如果链表无环，返回空
Node* hasycle(Node* head)
{
	//先确保有环
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
//复杂链表的赋值
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
	//进行random操作
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
	//进行新链表拆出来
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
//二叉树的操作
#include <iostream>
using namespace std;
//二叉树的构造
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
		pRoot = new TreeNode(arr[*index]);//先构造根结点
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
//二叉树的拷贝
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
//二叉树的销毁
void Destroy(TreeNode** pRoot)
{
	if (*pRoot)
	{
		Destroy(&(*pRoot)->_pRight);//先销毁右子树
		Destroy(&(*pRoot)->_pLeft);
		free(*pRoot);
		*pRoot = nullptr;
	}
}
//二叉树先序中序后序递归遍历
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
//先序中序后序非递归遍历
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
//层序遍历
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
//获取二叉树中节点的个数方法1
int GetCount1(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = GetCount1(pRoot->_pLeft);
	int right = GetCount1(pRoot->_pRight);
	return left + right + 1;
}
//获取二叉树中节点的个数方法2
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
	cout << "创建二叉树成功" << endl;
	TreeNode* pNewNode = CopyTree(a);
	cout << "拷贝二叉树成功" << endl;
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
	cout << "结点个数为:" << count << endl;
	count = GetCount2(a);
	cout << "结点个数为:" << count << endl;
	return 0;
}