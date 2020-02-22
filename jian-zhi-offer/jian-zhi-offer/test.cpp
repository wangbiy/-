#include <iostream>
using namespace std;
#include <vector>
//1.二维数组中的查找
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
//2.将一个字符串中的每个空格替换成“%20”
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
//按链表从尾到头的顺序打印ArrayList
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
//重建二叉树，直到前序序列和中序序列，得出二叉树
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL) {}
};
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (vin.size() == 0)
		return nullptr;
	int len = vin.size();
	int flag = 0;
	TreeNode* root = new TreeNode(pre[0]);
	for (int i = 0; i < len; ++i)
	{
		if (pre[0] == vin[i])
			flag = i;
	}
	vector<int> preleft, vinleft, preright, vinright;
	for (int i = 0; i < flag; ++i)
	{
		preleft.push_back(pre[i + 1]);
		vinleft.push_back(vin[i]);
	}
	for (int i = flag + 1; i < len; ++i)
	{
		preright.push_back(pre[i]);
		vinright.push_back(vin[i]);
	}
	root->left = reConstructBinaryTree(preleft, vinleft);
	root->right = reConstructBinaryTree(preright, vinright);
	return root;
}
//旋转数组的最小元素
int minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.empty())
		return 0;
	//分为是否旋转两种情况，如果没有，一定是非递减排序
	if (rotateArray.size() == 1 || rotateArray[0] < rotateArray.back())
		return rotateArray[0];
	int left = 0;
	int right = rotateArray.size();
	//如果有旋转，使用二分查找
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (rotateArray[0] <= rotateArray[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return rotateArray[left];
}
//斐波那契数列
//递归算法
int Fibonacci1(int n) 
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}
//动态规划算法
int Fibonacci2(int n) 
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	int* arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		//状态转换方程
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
	delete[]arr;
}
//跳台阶一只青蛙一次可以跳上1级台阶，
//也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
int jumpFloor(int number) 
{
	if (number == 0)
		return 0;
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	int* arr = new int[number + 1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= number; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[number];
	delete[]arr;
}
int main()
{
	vector<vector<int>> array{{ 1, 2, 3 } ,{4, 5, 6} , {7, 8, 9}};
	if (Find(3, array))
		cout << "可以找到" << endl;
	else
		cout << "找不到" << endl;

	char* str = "we are happy";
	replaceSpace(str, strlen(str));
	cout << str << endl;

	vector<int> rotateArray{ 3, 4, 5, 1, 2 };
	int ret = minNumberInRotateArray(rotateArray);
	cout << ret << endl;

	int r = Fibonacci1(5);
	cout << r << endl;
	r = Fibonacci2(5);
	cout << r << endl;
	return 0;
}