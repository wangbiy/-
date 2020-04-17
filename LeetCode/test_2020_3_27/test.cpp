#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
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
int max(int a, int b)
{
	return a > b ? a : b;
}
//无重复子串的最大长度
int lengthOfLongestSubstring(string s)
{
	vector<int> table(128, -1);
	int left = -1;
	int right, maxlen = 0;
	for (right = 0; right < s.size(); ++right)
	{
		if (table[s[right]] == -1 || left>table[s[right]])
			table[s[right]] = right;
		else
		{
			maxlen = max(maxlen, right - left - 1);
			left = table[s[right]];
			table[s[right]] = right;
		}
	}
	return max(maxlen, right - left - 1);
}
//最大回文长度
//使用从回文中间向左右推进的方法来实现回文串，然后在这些回文串中找最大的即可
#include <string>
string searchfromCenter(string s, int left, int right)
{
	while (left >= 0 && right < s.size())
	{
		if (s[left] == s[right])//继续推进
		{
			left--;
			right++;
		}
		else
			break;
	}
	return s.substr(left + 1, right - left - 1);//截取left和right中间的字符串，不包含left和right，这就是所得到的回文串
}
string longestPalindrome(string s)
{
	if (s.size() == 0 || s.size() == 1)
		return s;
	int maxLen = 1;//一开始最大回文串的长度是1，因为是单个字符表示回文串
	string result = s.substr(0, 1);
	for (int i = 0; i < s.size() - 1; ++i)
	{
		string s1 = searchfromCenter(s, i, i);//表示回文中间是一个字符的情况
		string s2 = searchfromCenter(s, i, i + 1);//表示回文中间是两个字符间隙的情况
		string s3 = s1.size()>s2.size() ? s1 : s2;
		if (maxLen < s3.size())
		{
			maxLen = s3.size();
			result = s3;
		}
	}
	return result;
}
//Z字形变换
string convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	vector<string> rows(min(numRows, int(s.size())));
	int cur = 0;//当前所在字符的位置，用来看什么时候对折
	bool goingdown = false;//用来表示是否已经到了要对折的点
	for (char e : s)
	{
		rows[cur] += e;
		if (cur == 0 || cur == numRows - 1)//开始对折
		{
			goingdown = !goingdown;
		}
		cur += goingdown ? 1 : -1;
	}
	string result;
	for (string row : rows)
		result += row;
	return result;
}
//整数反转
int reverse(int x)
{
	if (x == 0)
		return 0;
	long long _x = x;
	int sum = 0;
	bool flag = true;
	vector<int> arr(15, 0);
	int i = 0;//表示位数
	if (_x < 0)
	{
		flag = false;
		_x = 0 - _x;
	}
	while (_x)
	{
		sum = _x % 10;
		_x /= 10;
		arr[i] = sum;
		i++;
	}
	i -= 1;
	for (int j = 0; j <= i; ++j)
	{
		_x += (arr[j] * pow(10, i - j));
	}
	if (_x > (pow(2, 31) - 1) || _x < (pow(-2, 31)))
	{
		_x = 0;
	}
	else
	{
		if (!flag)//说明是负数
		{
			_x = 0 - _x;
		}
	}
	return _x;
}
//字符串转换函数atoi
int myAtoi(string s)
{
	//先将空格丢弃掉
	int i = 0;
	bool flag = true;
	int result = 0;
	while (s[i] == ' ')
	{
		i++;
	}
	if (s[i] == '-')
	{
		flag = false;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		i++;
	}
	//开始进行转换
	while (i < s.size() && isdigit(s[i]))
	{
		int tmp = s[i] - '0';
		if (result>INT_MAX / 10 || (result == INT_MAX / 10 && tmp > 7))
		{
			return 0;
		}
		result = result * 10 + tmp;
		i++;
	}
	return flag ? result : -result;
}
//盛最多水的容器
//也就是输入一个数组，每个数组的元素值是当前容器垂直线的高度，构成坐标，要算能容纳最多的容积
//使用两个指针，一个从左遍历，一个从右遍历，向中间推进，直到相交，如果左边的高度小于右边的，
//将此时两者之间的容积保存，然后左边的向右推进，右边的高度如果小于左边的也是先保存两者之间容积，
//然后向中间推进，每推进一次，将此时保存的容积与上一次最大的容积比较得出最大的即可
int maxArea(vector<int>& height)
{
	if (height.size() < 2)
		return 0;
	int left = 0;
	int right = height.size() - 1;
	int sum = 0;//保存每次的容积
	int max = 0;//保存每次比较的最大的容积
	while (left < right)//不能相交，因此不能=
	{
		if (height[left] < height[right])
		{
			sum = (right - left)*height[left];
			left++;
		}
		else
		{
			sum = (right - left)*height[right];
			right--;
		}
		max = max>sum ? max : sum;
	}
	return max;
}
#if 0
//给定二叉树的所有左叶子结点之和
int sum(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	//先去当前结点的左节点看,若它的左节点是叶子结点，加上，然后也要加上去当前结点的右节点去看
	if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
		return root->left->val + sum(root->right);
	//否则要去左子树和右子树中去看
	return sum(root->left) + sum(root->right);
}
#endif
#if 0
//路径总和
//给定一个二叉树，它的每个结点都存放着一个整数值。
//找出路径和等于给定数值的路径总数。
//路径不需要从根节点开始，也不需要在叶子节点结束，
//但是路径方向必须是向下的（只能从父节点到子节点）
//给一个从当前结点开始计算路径树的函数
int help(TreeNode* root, int sum)
{
	if (root == nullptr)
		return 0;
	sum -= root->val;
	return (sum == 0 ? 1 : 0) + help(root->left, sum) + help(root->right, sum);
}
//然后根结点调用help函数，然后递归根结点的左子树和右子树即可，因为题目要求可以从任何结点开始计算路径数
int pathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return 0;
	return help(root, sum) + pathSum(root->left, sum) + path(root->right, sum);
}
#endif
#if 0
//寻找二叉搜索树中的众数
//首先进行中序遍历，将中序遍历的每一个元素及其出现的次数存放在map中
//然后遍历map，如果次数大于max,max就等于这个次数，这样就找到了哪个元素出现次数最多的次数
//然后再遍历map只要哪个元素的次数等于max，就将这个元素放进结果数组中
class Solution
{
private:
	map<int, int> m;
	map<int, int>::iterator it;
	void inorder(TreeNode* root)
	{
		if (root == nullptr)
			return;
		inorder(root->left);
		m[root->val]++;
		inorder(root->right);
	}
public:
	vector<int> findMode(TreeNode* root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		int maxValue = 0;
		inorder(root);
		for (it = m.begin(); it != m.end(); ++it)
		{
			if (it->second < maxValue)
			{
				maxValue = it->second;
			}
		}
		for (it = m.begin(); it != m.end(); ++it)
		{
			if (it->second == maxValue)
				result.push_back(it->first);
		}
		return result;
	}
};
#endif
int main()
{
	vector<int> nums{ 2, 3, 1, 4, 5 };
	int target = 6;
	vector<int> result = twonum(nums, target);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";

	int len = lengthOfLongestSubstring("abcabcabc");
	cout << len << endl;

	string ret = longestPalindrome("babad");

	string str = "LEETCODEISHIRING";
	ret = convert(str, 3);
	cout << ret << endl;

	int num = reverse(-123);
	cout << num << endl;
	num = myAtoi("  -123 to hello");
	cout << num << endl;

	vector<int> height{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int max = maxArea(height);
	cout << max << endl;
	return 0;
}