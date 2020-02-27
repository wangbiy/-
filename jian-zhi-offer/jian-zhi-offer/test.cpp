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
//�ؽ���������ֱ��ǰ�����к��������У��ó�������
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
//��ת�������СԪ��
int minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.empty())
		return 0;
	//��Ϊ�Ƿ���ת������������û�У�һ���Ƿǵݼ�����
	if (rotateArray.size() == 1 || rotateArray[0] < rotateArray.back())
		return rotateArray[0];
	int left = 0;
	int right = rotateArray.size();
	//�������ת��ʹ�ö��ֲ���
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
//쳲���������
//�ݹ��㷨
int Fibonacci1(int n) 
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}
//��̬�滮�㷨
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
		//״̬ת������
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
	delete[]arr;
}
//��̨��һֻ����һ�ο�������1��̨�ף�
//Ҳ��������2���������������һ��n����̨���ܹ��ж���������
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
//��̬��̨�ף�һ�ο�����1�ס�2��.....n��
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
//���θ���
int rectCover(int number)
{
	if (number == 0)
		return 0;
	if (number == 1 || number == 2)
		return number;
	return rectCover(number - 1) + rectCover(number - 2);
}
//��������1�ĸ���
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
//��ֵ�������η�����base��exponent�Ĵη�
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
//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
//����֤������������ż����ż��֮������λ�ò��䡣
void reOrderArray(vector<int> &array)
{
	int len = array.size();
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			if (array[j] % 2 == 0 && array[j + 1] % 2 != 0)//˵��ǰ�����ż���������������
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
//���ǿ���֪������������Ŀ���չ�Էǳ�ǿ���������и������ڷǸ�����ǰ�棬
//�ܹ���3���������ڲ��ܱ�3����������ǰ��ȵȣ��������Ǿ���Ҫ���ǽ������Ĺ��ܳ��������
//���ú���ָ���ԭ����
//˳ʱ���ӡ�������磬�����������4 X 4����:1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
vector<int> printMatrix(vector<vector<int>> matrix)
{
	vector<int> result;
	int row = matrix.size();
	int col = matrix[0].size();
	if (matrix.empty() || row==0 || col==0)
		return result;
	int start = 0;//����������Ͻǵ�����
	while (row > start * 2 && col > start * 2)
	{
		//��һ��
		for (int i = start; i <= col - 1 - start; ++i)
		{
			result.push_back(matrix[start][i]);
		}
		//���һ��
		if (start < row - 1 - start)
		{
			//�����һ�е�start+1��Ԫ�ؿ�ʼ����Ϊstart���Ѿ��������
			for (int i = start + 1; i <= row - 1 - start; ++i)
			{
				result.push_back(matrix[i][col - 1 - start]);
			}
		}
		//���һ��
		if (start < row - 1 - start && start < col - 1 - start)
		{
			for (int i = col - 1 - 1 - start; i >= start; --i)
			{
				result.push_back(matrix[row - 1 - start][i]);
			}
		}
		//��һ��
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
		cout << "�����ҵ�" << endl;
	else
		cout << "�Ҳ���" << endl;

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
	cout << "������" << count << "��" << endl;

	count = jumpFloorII2(4);
	cout << "������" << count << "��" << endl;

	count = rectCover(5);
	cout << "���θ��Ƿ�����" << count << "��" << endl;

	count = NumberOf1(5);
	cout << "5�Ķ�������1�ĸ���Ϊ" << count << endl;

	double sum = Power(3.1, 2);
	cout << "3.1��2�η�Ϊ" << sum << endl;

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