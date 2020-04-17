#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
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
int max(int a, int b)
{
	return a > b ? a : b;
}
//���ظ��Ӵ�����󳤶�
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
//�����ĳ���
//ʹ�ôӻ����м��������ƽ��ķ�����ʵ�ֻ��Ĵ���Ȼ������Щ���Ĵ��������ļ���
#include <string>
string searchfromCenter(string s, int left, int right)
{
	while (left >= 0 && right < s.size())
	{
		if (s[left] == s[right])//�����ƽ�
		{
			left--;
			right++;
		}
		else
			break;
	}
	return s.substr(left + 1, right - left - 1);//��ȡleft��right�м���ַ�����������left��right����������õ��Ļ��Ĵ�
}
string longestPalindrome(string s)
{
	if (s.size() == 0 || s.size() == 1)
		return s;
	int maxLen = 1;//һ��ʼ�����Ĵ��ĳ�����1����Ϊ�ǵ����ַ���ʾ���Ĵ�
	string result = s.substr(0, 1);
	for (int i = 0; i < s.size() - 1; ++i)
	{
		string s1 = searchfromCenter(s, i, i);//��ʾ�����м���һ���ַ������
		string s2 = searchfromCenter(s, i, i + 1);//��ʾ�����м��������ַ���϶�����
		string s3 = s1.size()>s2.size() ? s1 : s2;
		if (maxLen < s3.size())
		{
			maxLen = s3.size();
			result = s3;
		}
	}
	return result;
}
//Z���α任
string convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	vector<string> rows(min(numRows, int(s.size())));
	int cur = 0;//��ǰ�����ַ���λ�ã�������ʲôʱ�����
	bool goingdown = false;//������ʾ�Ƿ��Ѿ�����Ҫ���۵ĵ�
	for (char e : s)
	{
		rows[cur] += e;
		if (cur == 0 || cur == numRows - 1)//��ʼ����
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
//������ת
int reverse(int x)
{
	if (x == 0)
		return 0;
	long long _x = x;
	int sum = 0;
	bool flag = true;
	vector<int> arr(15, 0);
	int i = 0;//��ʾλ��
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
		if (!flag)//˵���Ǹ���
		{
			_x = 0 - _x;
		}
	}
	return _x;
}
//�ַ���ת������atoi
int myAtoi(string s)
{
	//�Ƚ��ո�����
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
	//��ʼ����ת��
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
//ʢ���ˮ������
//Ҳ��������һ�����飬ÿ�������Ԫ��ֵ�ǵ�ǰ������ֱ�ߵĸ߶ȣ��������꣬Ҫ�������������ݻ�
//ʹ������ָ�룬һ�����������һ�����ұ��������м��ƽ���ֱ���ཻ�������ߵĸ߶�С���ұߵģ�
//����ʱ����֮����ݻ����棬Ȼ����ߵ������ƽ����ұߵĸ߶����С����ߵ�Ҳ���ȱ�������֮���ݻ���
//Ȼ�����м��ƽ���ÿ�ƽ�һ�Σ�����ʱ������ݻ�����һ�������ݻ��Ƚϵó����ļ���
int maxArea(vector<int>& height)
{
	if (height.size() < 2)
		return 0;
	int left = 0;
	int right = height.size() - 1;
	int sum = 0;//����ÿ�ε��ݻ�
	int max = 0;//����ÿ�αȽϵ������ݻ�
	while (left < right)//�����ཻ����˲���=
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
//������������������Ҷ�ӽ��֮��
int sum(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	//��ȥ��ǰ������ڵ㿴,��������ڵ���Ҷ�ӽ�㣬���ϣ�Ȼ��ҲҪ����ȥ��ǰ�����ҽڵ�ȥ��
	if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
		return root->left->val + sum(root->right);
	//����Ҫȥ����������������ȥ��
	return sum(root->left) + sum(root->right);
}
#endif
#if 0
//·���ܺ�
//����һ��������������ÿ����㶼�����һ������ֵ��
//�ҳ�·���͵��ڸ�����ֵ��·��������
//·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ������
//����·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩
//��һ���ӵ�ǰ��㿪ʼ����·�����ĺ���
int help(TreeNode* root, int sum)
{
	if (root == nullptr)
		return 0;
	sum -= root->val;
	return (sum == 0 ? 1 : 0) + help(root->left, sum) + help(root->right, sum);
}
//Ȼ���������help������Ȼ��ݹ�����������������������ɣ���Ϊ��ĿҪ����Դ��κν�㿪ʼ����·����
int pathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return 0;
	return help(root, sum) + pathSum(root->left, sum) + path(root->right, sum);
}
#endif
#if 0
//Ѱ�Ҷ����������е�����
//���Ƚ�����������������������ÿһ��Ԫ�ؼ�����ֵĴ��������map��
//Ȼ�����map�������������max,max�͵�������������������ҵ����ĸ�Ԫ�س��ִ������Ĵ���
//Ȼ���ٱ���mapֻҪ�ĸ�Ԫ�صĴ�������max���ͽ����Ԫ�طŽ����������
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