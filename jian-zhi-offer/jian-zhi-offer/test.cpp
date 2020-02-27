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
//变态跳台阶，一次可以跳1阶、2阶.....n阶
int jumpFloorII1(int number)
{
	if (number == 0)
		return 0;
	int ret = 1;
	for (int i = 2; i <= number; ++i)
	{
		ret *= 2;
	}
	return ret;
}
int jumpFloorII2(int number)
{
	if (number == 0)
		return 0;
	return 1 << (number - 1);
}
//矩形覆盖
int rectCover(int number)
{
	if (number == 0)
		return 0;
	if (number == 1 || number == 2)
		return number;
	return rectCover(number - 1) + rectCover(number - 2);
}
//二进制中1的个数
int NumberOf1(int n)
{
	if (n == 0)
		return 0;
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);
	}
	return count;
}
//数值的整数次方，求base的exponent的次方
double Power(double base, int exponent)
{
	if (base == 0)
		return 0;
	double sum = 1;
	int e = exponent;
	if (exponent < 0)
	{
		e = -exponent;
	}
	while (e != 0)
	{
		sum *= base;
		e--;
	}
	if (exponent < 0)
		sum = 1 / sum;
	return sum;
}
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。
void reOrderArray(vector<int> &array)
{
	int len = array.size();
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			if (array[j] % 2 == 0 && array[j + 1] % 2 != 0)//说明前面的是偶数，后面的是奇数
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
//我们可以知道，此种问题的可扩展性非常强，比如所有负数都在非负数的前面，
//能够被3整除的数在不能被3整除的数的前面等等，这样我们就需要考虑将这样的功能抽象出来，
//利用函数指针的原理即可
//顺时针打印矩形例如，如果输入如下4 X 4矩阵:1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
vector<int> printMatrix(vector<vector<int>> matrix)
{
	vector<int> result;
	int row = matrix.size();
	int col = matrix[0].size();
	if (matrix.empty() || row==0 || col==0)
		return result;
	int start = 0;//用来标记左上角的坐标
	while (row > start * 2 && col > start * 2)
	{
		//第一行
		for (int i = start; i <= col - 1 - start; ++i)
		{
			result.push_back(matrix[start][i]);
		}
		//最后一列
		if (start < row - 1 - start)
		{
			//从最后一列的start+1行元素开始，因为start行已经插入过了
			for (int i = start + 1; i <= row - 1 - start; ++i)
			{
				result.push_back(matrix[i][col - 1 - start]);
			}
		}
		//最后一行
		if (start < row - 1 - start && start < col - 1 - start)
		{
			for (int i = col - 1 - 1 - start; i >= start; --i)
			{
				result.push_back(matrix[row - 1 - start][i]);
			}
		}
		//第一列
		if (start < col - 1 - start && start < row - 1 - 1 - start)
		{
			for (int i = row - 1 - 1 - start; i >= start + 1; --i)
			{
				result.push_back(matrix[i][start]);
			}
		}
		start++;
	}
	return result;
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

	int count=jumpFloorII1(4);
	cout << "跳法有" << count << "种" << endl;

	count = jumpFloorII2(4);
	cout << "跳法有" << count << "种" << endl;

	count = rectCover(5);
	cout << "矩形覆盖方法有" << count << "种" << endl;

	count = NumberOf1(5);
	cout << "5的二进制中1的个数为" << count << endl;

	double sum = Power(3.1, 2);
	cout << "3.1的2次方为" << sum << endl;

	vector<int> a{ 1, 3, 2, 4, 5, 12, 8, 9, 10, 18, 24 };
	reOrderArray(a);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<vector<int>> matrix{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<int> b = printMatrix(matrix);
	for (auto e : b)
		cout << e << " ";
	cout << endl;
	return 0;
}