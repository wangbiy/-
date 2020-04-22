#include <iostream>
using namespace std;
#include <vector>
#if 0
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
//数组中出现次数大于数组一半的元素
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int len = numbers.size();
	if (len == 0)
		return 0;
	int times = 1;
	int ret = numbers[0];
	for (int i = 0; i<len; ++i)
	{
		if (times == 0)
		{
			ret = numbers[i];
			times = 1;
		}
		else if (numbers[i] == ret)
			times++;
		else times--;
	}
	times = 0;
	for (int i = 0; i<len; ++i)
	{
		if (ret == numbers[i])
			times++;
	}
	return times>len / 2 ? ret : 0;
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

	vector<int> c{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	count = MoreThanHalfNum_Solution(c);
	cout << "数组中出现次数超过数组大小一半的元素是" << count << endl;
	return 0;
}
#endif
//字符串的排列：abc-abc/acb/bac/bca/cab/cba
#include <algorithm>
class S
{
private:
	vector<string> result;
public:
	vector<string> Permutation(string str)
	{
		if (str.empty())
			return result;
		Helper(str, 0);
		sort(result.begin(), result.end());//结果是按照字符串大小排序的，因此先要排序才能返回
		return result;
	}
private:
	void Helper(string str, int begin)
	{
		if (begin == str.size())//递归条件
		{
			result.push_back(str);
			return;
		}
		else
		{
			for (int i = begin; str[i] != '\0'; ++i)
			{
				if (i != begin && str[i] == str[begin])//如果首字符后面又和他相同的字符，不用交换
					continue;
				swap(str[i], str[begin]);//以a为首字符的情况，循环一次为以b为首字符的情况，再循环一次为c为首字符的情况
				Helper(str, begin + 1);//首字符其后的字符进行递归
				swap(str[i], str[begin]);//依次让b/c为首字符，每循环一次交换一次，第一次是a为首字符
			}
		}
	}
};
//数组中出现次数超过一半的元素
int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	if (numbers.empty())
		return 0;
	int len = numbers.size();
	int count = 1;
	int ret = numbers[0];
	for (int i = 0; i<len; ++i)
	{
		if (count == 0)
		{
			ret = numbers[i];
			count = 1;
		}
		else if (ret == numbers[i])
			count++;
		else
			count--;
	}
	//ret存数组中的一个数字，count存次数
	//一开始ret存数组第一个数字，count为1，遍历数组，如果与ret相同，count++，如果不同就--
	//如果中间count为0，表示之前的数字达到的次数不是之前所有元素出现次数的一半已经抵消了
	//因此这样下来，最后一个把次数设为1的数一定是找的数，放入ret中
	count = 0;
	for (int i = 0; i<len; ++i)
	{
		if (ret == numbers[i])
			count++;
	}
	return count>len / 2 ? ret : 0;
}
//输入n个整数，找出其中最小的K个数，
//例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
{
	vector<int> result;
	if (input.empty() || k == 0 || k > input.size())
		return result;
	sort(input.begin(), input.end());
	for (int i = 0; i < k; ++i)
	{
		result.push_back(input[i]);
	}
	return result;
}
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k)
{
	vector<int> result;
	if (input.empty() || k == 0 || k>input.size())
		return result;
	for (int i = 0; i < k; ++i)
	{
		result.push_back(input[i]);
	}
	make_heap(result.begin(), result.end());//前k个元素建大堆
	for (int i = k; i < input.size(); ++i)
	{
		if (input[i] < result[0])//剩下的元素与堆顶元素相比，如果比他小就rag堆顶元素出来，插入这个元素
		{
			pop_heap(result.begin(), result.end());
			result.pop_back();
			result.push_back(input[i]);
			push_heap(result.begin(), result.end());
		}
	}
	sort(result.begin(), result.end());
	return result;
}
//连续子数组的最大和
int FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.empty())
		return 0;
	int maxSum = array[0];
	int sum = array[0];
	for (int i = 1; i < array.size(); ++i)
	{
		sum = (sum>0) ? (sum + array[i]) : array[i];
		maxSum = (maxSum < sum) ? sum : maxSum;
	}
	return maxSum;
}
//字符串过滤deefd---def
void stringfiler(const char* s1, int len, char* s2)
{
	if (s1 == nullptr)
		return;
	int hash[26];
	for (int i = 0; i < 26; ++i)
	{
		hash[i] = 0;
	}
	int k = 0;
	for (int i = 0; i < len; ++i)
	{
		int index = s1[i] - 'a';//转换为数字
		if (hash[index] == 0)//说明s2中没有这个元素
		{
			s2[k++] = s1[i];
		}
		//这里说明s2中存在这个元素和在放入元素后的操作
		hash[index] = 1;
	}
	s2[k] = '\0';
	for (int i = 0; i < k; ++i)
	{
		cout << s2[i];
	}
	cout << endl;
}
//1的个数
#if 0
//首先使用暴力法
int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	for (int i = 0; i <= n; ++i)
	{
		int t = i;
		while (t % 10 == 1)
			count++;
		t /= 10;
	}
	return count;
}
#endif
//另一种方法就是使用更高位和更低位表示
//例如我们计算cur位的数，要收到三种影响：
//1.当前cur位的数、2.cur位以上的数、3.cur位以下的数
//例如若cur位为0（例如12013，此时我们cur位是百位），则百位出现1的情况就是：
//100到199、1100到1199、2100到2199、.......11100到11199，共1200个，也就是12*100
//而百位（cur位）为1时，例如12113，则百位出现1的情况为：
//100到199,1100到1199,2100到2199，。。。11100到11199，也是12*100个，
//此时还要考虑更低位的情况，为12100到12113，共14个，也就是13（更低位）+1
//如果cur位（百位）大于0，例如12213，此时百位为1的情况就是：
//100到199,1100到1199,2100到2199.。。11100到11199,12100到12199，共1300个
//此时也就是（12+1）*100，也就是（更高位+1)*100
int NumberOf1Between1AndN_Solution(int n)
{
	int i = 1;//通过i来计算cur位
	int count = 0;
	while (n / i != 0)
	{
		int before = n / i / 10;
		int after = n%i;
		int cur = (n / i) % 10;
		if (cur == 0)
			count += before*i;
		else if (cur == 1)
			count += before*i + after + 1;
		else
			count += (before + 1)*i;
		i *= 10;
	}
	return count;
}
//计算一个字符串的空格数并且删除
#include <assert.h>
int delSpace(char *pStr)
{
	assert(pStr);
	char* tmp = pStr;
	int count = 0;
	while (*tmp != '\0')
	{
		while (*tmp == ' ')
		{
			count++;
			tmp++;
		}
		//记录一下当前位置
		if (*tmp == '\0')//如果已经到达末尾
		{
			return count;
		}
		tmp++;
	}
	return count;
}
int main()
{
	S s;
	vector<string> v = s.Permutation("abc");
	vector<int> arr{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int ret = MoreThanHalfNum_Solution(arr);
	cout << ret << endl;
	vector<int> result1= GetLeastNumbers_Solution1(arr, 3);
	vector<int> result2 = GetLeastNumbers_Solution2(arr, 3);
	vector<int> array{6, -3, -2, 7, -15, 1, 2, 2};
	int n = FindGreatestSumOfSubArray(array);
	cout << n << endl;

	char* s1 = "deefd";
	int len = strlen(s1);
	char* s2 = new char(len);;
	stringfiler(s1, len, s2);

	int count = NumberOf1Between1AndN_Solution(12013);
	cout << count << endl;

	char* str = "a b c f  g";
	count=delSpace(str);
	cout << "空格个数为：" << count << endl;
	return 0;
}