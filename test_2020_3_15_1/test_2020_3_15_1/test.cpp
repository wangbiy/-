#define _CRT_SECURE_NO_WARNINGS 1
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
	while (pCur != nullptr || !s.empty())
	{
		while (pCur != nullptr)
		{
			cout << pCur->_val<<" ";
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
	while (pCur != nullptr || !s.empty())
	{
		while (pCur != nullptr)
		{
			s.push(pCur);
			pCur = pCur->_pLeft;
		}
		TreeNode* top = s.top();
		cout << top->_val<<" ";
		s.pop();
		pCur = top->_pRight;
	}
}
void postorderNOR(TreeNode* pRoot)
{
	TreeNode* pCur = pRoot;
	TreeNode* last = nullptr;
	stack<TreeNode*> s;
	while (pCur != nullptr || !s.empty())
	{
		while (pCur != nullptr)
		{
			s.push(pCur);
			pCur = pCur->_pLeft;
		}
		TreeNode* top = s.top();
		if (top->_pRight == nullptr || top->_pRight == last)
		{
			cout << top->_val<<" ";
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
//���������Ҷ�ӽ�����
int Getleafcount(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	else if (pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr)
		return 1;
	else
		return Getleafcount(pRoot->_pLeft) + Getleafcount(pRoot->_pRight);
}
//��������ĸ߶�
int Max(int a, int b)
{
	return a >= b ? a : b;
}
int GetHeight(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = GetHeight(pRoot->_pLeft);
	int right = GetHeight(pRoot->_pRight);
	return Max(left, right) + 1;
}
//�ж�һ���������Ƿ�Ϊƽ�������
bool isBalanced(TreeNode* pRoot)//O(n^2)
{
	if (pRoot == nullptr)
		return true;
	int h1 = GetHeight(pRoot->_pLeft);
	int h2 = GetHeight(pRoot->_pRight);
	int d = abs(h1 - h2);
	return (d <= 1) && isBalanced(pRoot->_pLeft) && isBalanced(pRoot->_pRight);
}
bool _isBalanced_p(TreeNode* pRoot,int* height)//O(n)
{
	int lIsbalance = 0;
	int rIsbalance = 0;
	int lheight = 0;
	int rheight = 0;
	if (pRoot == nullptr)
		return true;
	//����������Ҫƽ��
	lIsbalance = _isBalanced_p(pRoot->_pLeft, &lheight);
	rIsbalance = _isBalanced_p(pRoot->_pRight, &rheight);
	if (lIsbalance&&rIsbalance && abs(lheight - rheight) < 2)
	{
		*height = lheight>rheight ? lheight + 1 : rheight + 1;
		return true;
	}
	return false;
}
bool isBalanced_p(TreeNode* pRoot)
{
	int height = 0;
	return _isBalanced_p(pRoot, &height);
}
//��ȡ��������k����ĸ���
#include <assert.h>
int GetkLevelCount(TreeNode* pRoot,int k)
{
	assert(k >= 1);
	if (k == 1)
		return 1;//����㣬Ҳ���ǵݹ����ֹ����
	return GetkLevelCount(pRoot->_pLeft, k - 1) + GetkLevelCount(pRoot->_pRight, k - 1);
}
//����������ֵΪv�Ľ���ַ
TreeNode* Find(TreeNode* pRoot, char v)
{
	if (pRoot == nullptr)
		return nullptr;
	else if (pRoot->_val == v)
		return pRoot;
	else
	{
		TreeNode* left=Find(pRoot->_pLeft, v);
		if (left != nullptr)//Ҳ����������ҵ���
			return left;
		return Find(pRoot->_pRight, v);
	}
}
//����ָ������˫�׽ڵ�
TreeNode* GetParent(TreeNode* pRoot, TreeNode* node)
{
	TreeNode* pParent = nullptr;
	if (pRoot == nullptr || node == nullptr)
		return nullptr;
	if (pRoot == node)//����Ǹ���㣬û��˫�ף�����nullptr
		return nullptr;
	if (pRoot->_pLeft == node || pRoot->_pRight == node)//pRoot��������˫��
		return pRoot;
	//�����������ң��ݹ�������ϲ���
	pParent = GetParent(pRoot->_pLeft, node);
	if (pParent != nullptr)//˵�������������ҵ���
		return pParent;
	return GetParent(pRoot->_pRight, node);
}
//�ж϶������Ƿ�����ȫ������,������������������սڵ㣬����Ľڵ�һ���ǿ�
bool isCompleteTree(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return true;
	queue<TreeNode*> q;
	q.push(pRoot);
	while (1)
	{
		TreeNode* front = q.front();
		q.pop();
		if (front == nullptr)//�����սڵ�
			break;//����ѭ��
		q.push(front->_pLeft);
		q.push(front->_pRight);
	}
	//�ߵ�����˵���Ѿ�����Ҷ�ӽ�㲢���ǿսڵ�������
	while (!q.empty())
	{
		TreeNode* front = q.front();
		q.pop();
		if (front != nullptr)
			return false;
	}
	return true;
}
//�ж϶���������
bool isMirror(TreeNode* s,TreeNode* t)
{
	if (s == nullptr && t == nullptr)
		return true;
	if (s == nullptr || t == nullptr)
		return false;
	return s->_val == t->_val && isMirror(s->_pLeft, t->_pRight) && isMirror(s->_pRight, t->_pLeft);
}
//������������
//������ö������Ƿ���ͬ
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;
	if (p == nullptr || q == nullptr)
		return false;
	return p->_val == q->_val && isSameTree(p->_pLeft, q->_pLeft) && isSameTree(p->_pRight, q->_pRight);
}
//�ж�һ�����Ƿ�Ϊ��һ����������
bool isSubTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr)
		return false;
	if (p->_val == q->_val)
	{
		if(isSameTree(p, q))
			return true;
	}
	bool left = isSubTree(p->_pLeft, q);
	if (left == true)
		return true;
	return isSubTree(p->_pRight, q);
}
//�ж϶Գƶ�����
bool isSymmetric(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return true;
	return isMirror(pRoot->_pLeft, pRoot->_pRight);
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
	count = Getleafcount(a);
	cout << "Ҷ�ӽ�������:" << count << endl;
	count = GetHeight(a);
	cout << "������a�ĸ߶���:" << count << endl;
	bool flag = isBalanced(a);
	if (flag == true)
		cout << "��ƽ�������" << endl;
	else
		cout << "����ƽ�������" << endl;
	flag = isBalanced_p(a);
	if (flag == true)
		cout << "��ƽ�������" << endl;
	else
		cout << "����ƽ�������" << endl;
	count = GetkLevelCount(a, 3);
	cout << "a��������3��Ľ�������:" << count << endl;
	TreeNode* p = Find(a, 'F');
	cout << p->_val << endl;
	p = GetParent(a, Find(a,'F'));
	cout << p->_val << endl;
	flag = isCompleteTree(a);
	if (flag == true)
		cout << "����ȫ������" << endl;
	else
		cout << "������ȫ������" << endl;
	flag = isMirror(a, pNewNode);
	if (flag == true)
		cout << "a��pNewNode�Ǿ���" << endl;
	else
		cout << "a��pNewNode���Ǿ���" << endl;
	flag = isSameTree(a, pNewNode);
	if (flag == true)
		cout << "���ö�������ͬ" << endl;
	else
		cout << "���ö���������ͬ" << endl;
	flag = isSubTree(a, pNewNode);
	if (flag == true)
		cout << "����������" << endl;
	else
		cout << "������������" << endl;
	flag = isSymmetric(a);
	if (flag)
		cout << "�ǶԳƶ�����" << endl;
	else
		cout << "���ǶԳƶ�����" << endl;
	return 0;
}
#endif
#if 0
//����������������
//����ǰ������������������������
struct TreeNode
{
	TreeNode* _pLeft;
	TreeNode* _pRight;
	int _val;
	TreeNode(int val)
		:_val(val)
		, _pLeft(nullptr)
		, _pRight(nullptr)
	{}
};
#include <vector>
#include <iostream>
using namespace std;
TreeNode* BuildTree1(vector<int> preorder, vector<int> inorder)
{
	int size = inorder.size();
	if (size == 0)
		return nullptr;
	TreeNode* pRoot = new TreeNode(preorder[0]);//��������
	int flag = 0;
	for (int i = 0; i < size; ++i)
	{
		if (inorder[i] == preorder[0])//�������������Ҹ����
			flag = i;
	}
	vector<int> preleft, inleft, preright, inright;
	for (int i = 0; i < flag; ++i)
	{
		preleft.push_back(preorder[i + 1]);
		inleft.push_back(inorder[i]);
	}
	for (int i = flag + 1; i < size; ++i)
	{
		preright.push_back(preorder[i]);
		inright.push_back(inorder[i]);
	}
	//���еݹ鼴��
	pRoot->_pLeft = BuildTree1(preleft, inleft);
	pRoot->_pRight = BuildTree1(preright, inright);
	return pRoot;
}
//��������ͺ������д���������
TreeNode* BuildTree2(vector<int> inorder, vector<int> postorder)
{
	int size = inorder.size();
	if (size == 0)
		return nullptr;
	TreeNode* pRoot = new TreeNode(postorder[size - 1]);
	int flag = 0;
	for (int i = 0; i < size; ++i)
	{
		if (inorder[i] == postorder[size - 1])
		{
			flag = i;
			break;
		}
	}
	vector<int> inleft, inright, postleft, postright;
	for (int i = 0; i < flag; ++i)
	{
		inleft.push_back(inorder[i]);
		postleft.push_back(postorder[i]);
	}
	for (int i = flag + 1; i < size; ++i)
	{
		inright.push_back(inorder[i]);
		postright.push_back(postorder[i - 1]);
	}
	pRoot->_pLeft = BuildTree2(inleft, postleft);
	pRoot->_pRight = BuildTree2(inright, postright);
	return pRoot;
}
int main()
{
	vector<int> pre{ 1, 2, 4, 5, 8, 3, 6, 7 };
	vector<int> in{ 4, 2, 5, 8, 1, 6, 3, 7 };
	vector<int> post{ 4, 8, 5, 2, 6, 7, 3, 1 };
	TreeNode* pRoot1 = BuildTree1(pre, in);
	TreeNode* pRoot2 = BuildTree2(in, post);
	return 0;
}
#endif
//�����������ַ���
#include <iostream>
using namespace std;
struct TreeNode
{
	TreeNode* _pLeft;
	TreeNode* _pRight;
	char _val;
	TreeNode(char val)
		:_val(val)
		, _pLeft(nullptr)
		, _pRight(nullptr)
	{}
};
TreeNode* _CreateTree(char* arr, int size, int* index)
{
	TreeNode* pRoot = nullptr;
	if (*index < size && arr[*index] != '#')
	{
		pRoot = new TreeNode(arr[*index]);
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
#if 0
//�����ַ���,����ǰ������ķ�ʽ��һ��������ת��Ϊһ�������ź�������ɵ��ַ������սڵ���()��ʾ
char* _tree2str(TreeNode* pRoot, char* ret)
{
	if (pRoot == nullptr)
		return ret;
	char szvalue[32] = { 0 };
	sprintf(szvalue, "%d", pRoot->_val);
	strcat(ret, szvalue);//׷��
	if (nullptr == pRoot->_pLeft)//��������������Ϊ��
	{
		if (nullptr == pRoot->_pRight)//������ҲΪ��
		{
			return ret;
		}
		else//���������ǿգ��ȼ���()
		{
			strcat(ret, "()");
		}
	}
	else//�������������Ϊ��
	{
		strcat(ret, "(");
		_tree2str(pRoot->_pLeft, ret);//���������Ľ����ɼ���������
		strcat(ret, ")");
	}
	if (nullptr == pRoot->_pRight)//�жϸ�����������
		return ret;
	else
	{
		strcat(ret, "(");
		_tree2str(pRoot->_pRight, ret);
		strcat(ret, ")");
	}
	return ret;
}
char* tree2str(TreeNode* pRoot)
{
	char result[100000];
	result[0] = '\0';
	return _tree2str(pRoot, result);
}
int main()
{
	char arr[] = { 1, 2, 4, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	TreeNode* a = CreateTree(arr, size);
	char* ret = tree2str(a);
	cout << ret << endl;
	return 0;
}
#endif
//�����������
TreeNode* lowstCommonAncestor(TreeNode* pRoot,TreeNode* p,TreeNode* q)
{
	if (pRoot == p || pRoot == q || !pRoot)
		return pRoot;//���p��q���Ǹ���㣬�����ǵ�������������Ǹ����
	TreeNode* left = lowstCommonAncestor(pRoot->_pLeft, p, q);
	TreeNode* right = lowstCommonAncestor(pRoot->_pRight, p, q);
	//����������������֮��
	if (!left && !right)//����������û��
		return nullptr;
	if (!left && right)//���������������������Ҳ���
		return  right;
	if (left && !right)
		return left;
	return pRoot;//���������־�����
}
//����������ת��Ϊ˫����������
void ConvertHelp(TreeNode* pRoot, TreeNode* pre)
{
	if (pRoot == nullptr)
		return;
	//�����������˳����
	//�ȴ���������
	ConvertHelp(pRoot->_pLeft, pre);
	//��������
	pRoot->_pLeft = pre;
	if (pre)
	{
		pre->_pRight = pRoot;
	}
	//����������
	pre = pRoot;
	ConvertHelp(pRoot->_pRight, pre);
}
TreeNode* Convert(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return nullptr;
	TreeNode* pre = nullptr;
	ConvertHelp(pRoot, pre);
	//���Ҫ�������һ����㣬Ҳ���Ƕ���������ߵĽ���ʾ����������Ҫ�ҵ�����������ߵĽ��
	TreeNode* pCur = pRoot;
	while (pCur->_pLeft)
	{
		pCur = pCur->_pLeft;
	}
	return pCur;
}
TreeNode* find(TreeNode* pRoot, char val)
{
	if (pRoot == nullptr)
		return nullptr;
	else if (pRoot->_val == val)
		return pRoot;
	else
	{
		TreeNode* left = find(pRoot->_pLeft, val);
		if (left != nullptr)
			return left;
		return find(pRoot->_pRight, val);
	}
}

int main()
{
	char* str = "ABD##E#H##CF##G##";
	int size = strlen(str);
	TreeNode* a = CreateTree(str, size);
	TreeNode* common = lowstCommonAncestor(a, find(a,'D'), find(a,'E'));
	cout << common->_val << endl;
	TreeNode* so = Convert(a);
	return 0;
}
