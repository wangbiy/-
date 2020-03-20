#define _CRT_SECURE_NO_WARNINGS 1
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
//求二叉树的叶子结点个数
int Getleafcount(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	else if (pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr)
		return 1;
	else
		return Getleafcount(pRoot->_pLeft) + Getleafcount(pRoot->_pRight);
}
//求二叉树的高度
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
//判断一个二叉树是否为平衡二叉树
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
	//左右子树都要平衡
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
//获取二叉树第k层结点的个数
#include <assert.h>
int GetkLevelCount(TreeNode* pRoot,int k)
{
	assert(k >= 1);
	if (k == 1)
		return 1;//根结点，也就是递归的终止条件
	return GetkLevelCount(pRoot->_pLeft, k - 1) + GetkLevelCount(pRoot->_pRight, k - 1);
}
//二叉树查找值为v的结点地址
TreeNode* Find(TreeNode* pRoot, char v)
{
	if (pRoot == nullptr)
		return nullptr;
	else if (pRoot->_val == v)
		return pRoot;
	else
	{
		TreeNode* left=Find(pRoot->_pLeft, v);
		if (left != nullptr)//也就是在左边找到了
			return left;
		return Find(pRoot->_pRight, v);
	}
}
//查找指定结点的双亲节点
TreeNode* GetParent(TreeNode* pRoot, TreeNode* node)
{
	TreeNode* pParent = nullptr;
	if (pRoot == nullptr || node == nullptr)
		return nullptr;
	if (pRoot == node)//如果是根结点，没有双亲，返回nullptr
		return nullptr;
	if (pRoot->_pLeft == node || pRoot->_pRight == node)//pRoot就是它的双亲
		return pRoot;
	//在左子树中找，递归继续以上操作
	pParent = GetParent(pRoot->_pLeft, node);
	if (pParent != nullptr)//说明在左子树中找到了
		return pParent;
	return GetParent(pRoot->_pRight, node);
}
//判断二叉树是否是完全二叉树,即层序遍历程序碰到空节点，后面的节点一定是空
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
		if (front == nullptr)//遇到空节点
			break;//跳出循环
		q.push(front->_pLeft);
		q.push(front->_pRight);
	}
	//走到这里说明已经到了叶子结点并且是空节点的情况了
	while (!q.empty())
	{
		TreeNode* front = q.front();
		q.pop();
		if (front != nullptr)
			return false;
	}
	return true;
}
//判断二叉树镜像
bool isMirror(TreeNode* s,TreeNode* t)
{
	if (s == nullptr && t == nullptr)
		return true;
	if (s == nullptr || t == nullptr)
		return false;
	return s->_val == t->_val && isMirror(s->_pLeft, t->_pRight) && isMirror(s->_pRight, t->_pLeft);
}
//二叉树面试题
//检查两棵二叉树是否相同
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;
	if (p == nullptr || q == nullptr)
		return false;
	return p->_val == q->_val && isSameTree(p->_pLeft, q->_pLeft) && isSameTree(p->_pRight, q->_pRight);
}
//判断一棵树是否为另一棵树的子树
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
//判断对称二叉树
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
	count = Getleafcount(a);
	cout << "叶子结点个数是:" << count << endl;
	count = GetHeight(a);
	cout << "二叉树a的高度是:" << count << endl;
	bool flag = isBalanced(a);
	if (flag == true)
		cout << "是平衡二叉树" << endl;
	else
		cout << "不是平衡二叉树" << endl;
	flag = isBalanced_p(a);
	if (flag == true)
		cout << "是平衡二叉树" << endl;
	else
		cout << "不是平衡二叉树" << endl;
	count = GetkLevelCount(a, 3);
	cout << "a二叉树第3层的结点个数是:" << count << endl;
	TreeNode* p = Find(a, 'F');
	cout << p->_val << endl;
	p = GetParent(a, Find(a,'F'));
	cout << p->_val << endl;
	flag = isCompleteTree(a);
	if (flag == true)
		cout << "是完全二叉树" << endl;
	else
		cout << "不是完全二叉树" << endl;
	flag = isMirror(a, pNewNode);
	if (flag == true)
		cout << "a和pNewNode是镜像" << endl;
	else
		cout << "a和pNewNode不是镜像" << endl;
	flag = isSameTree(a, pNewNode);
	if (flag == true)
		cout << "两棵二叉树相同" << endl;
	else
		cout << "两棵二叉树不相同" << endl;
	flag = isSubTree(a, pNewNode);
	if (flag == true)
		cout << "是它的子树" << endl;
	else
		cout << "不是它的子树" << endl;
	flag = isSymmetric(a);
	if (flag)
		cout << "是对称二叉树" << endl;
	else
		cout << "不是对称二叉树" << endl;
	return 0;
}
#endif
#if 0
//二叉树进阶面试题
//根据前序遍历和中序遍历建立二叉树
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
	TreeNode* pRoot = new TreeNode(preorder[0]);//构造根结点
	int flag = 0;
	for (int i = 0; i < size; ++i)
	{
		if (inorder[i] == preorder[0])//在中序序列中找根结点
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
	//进行递归即可
	pRoot->_pLeft = BuildTree1(preleft, inleft);
	pRoot->_pRight = BuildTree1(preright, inright);
	return pRoot;
}
//根据中序和后序序列创建二叉树
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
//二叉树创建字符串
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
//创建字符串,采用前序遍历的方式将一个二叉树转换为一个由括号和整数组成的字符串，空节点用()表示
char* _tree2str(TreeNode* pRoot, char* ret)
{
	if (pRoot == nullptr)
		return ret;
	char szvalue[32] = { 0 };
	sprintf(szvalue, "%d", pRoot->_val);
	strcat(ret, szvalue);//追加
	if (nullptr == pRoot->_pLeft)//如果根结点左子树为空
	{
		if (nullptr == pRoot->_pRight)//右子树也为空
		{
			return ret;
		}
		else//右子树不是空，先加上()
		{
			strcat(ret, "()");
		}
	}
	else//根结点左子树不为空
	{
		strcat(ret, "(");
		_tree2str(pRoot->_pLeft, ret);//将左子树的解决完成加上右括号
		strcat(ret, ")");
	}
	if (nullptr == pRoot->_pRight)//判断根结点的右子树
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
//最近公共祖先
TreeNode* lowstCommonAncestor(TreeNode* pRoot,TreeNode* p,TreeNode* q)
{
	if (pRoot == p || pRoot == q || !pRoot)
		return pRoot;//如果p和q都是根结点，则他们的最近公共祖先是根结点
	TreeNode* left = lowstCommonAncestor(pRoot->_pLeft, p, q);
	TreeNode* right = lowstCommonAncestor(pRoot->_pRight, p, q);
	//在左右子树都找了之后
	if (!left && !right)//左右子树都没有
		return nullptr;
	if (!left && right)//在右子树，但是左子树找不到
		return  right;
	if (left && !right)
		return left;
	return pRoot;//左右子树分居两侧
}
//搜索二叉树转换为双向排序链表
void ConvertHelp(TreeNode* pRoot, TreeNode* pre)
{
	if (pRoot == nullptr)
		return;
	//按照中序遍历顺序处理
	//先处理左子树
	ConvertHelp(pRoot->_pLeft, pre);
	//处理根结点
	pRoot->_pLeft = pre;
	if (pre)
	{
		pre->_pRight = pRoot;
	}
	//处理右子树
	pre = pRoot;
	ConvertHelp(pRoot->_pRight, pre);
}
TreeNode* Convert(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return nullptr;
	TreeNode* pre = nullptr;
	ConvertHelp(pRoot, pre);
	//最后要用链表第一个结点，也就是二叉树最左边的结点表示这个链表，因此要找到二叉树最左边的结点
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
