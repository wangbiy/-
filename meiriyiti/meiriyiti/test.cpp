#include <iostream>
using namespace std;
#include <vector>
#if 0
//쳲�������β���������n��쳲����������������6λ�����ͷ��غ���λ����
int main()
{
	vector<int> fib(1000001);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 1000001; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= 1000000;
	}
	int n;
	while (cin >> n)
	{
		if (n < 29)
			printf("%d\n", fib[n]);
		else
			printf("%06d\n", fib[n]);
	}
	return 0;
}
#endif
#if 0
//���쳲�����������ĳһ�εĺ�
#define MAXSIZE 83
vector<long long> fibonacci(vector<long long>& arr)
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < MAXSIZE; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr;
}
//��ĳһ�εĺ�
long long Sum(vector<long long>& arr, int from, int to)
{
	return arr[to + 1] - arr[from];
}
int main()
{
	int from, to;
	vector<long long> arr(MAXSIZE);
	vector<long long> ret= fibonacci(arr);
	while (cin >> from >> to)
	{
		long long result = Sum(ret, from, to);
		cout << result << endl;
	}
	return 0;
}
#endif
#if 0
//һ����Ϣ���ղ���ӡ�Ľṹ���
//Ҳ��������1��N����һ������˳�����������ϴδ�ӡ������i����ô��i+1����
//ʱ����ӡi+1����֮����չ��Ĳ�����������������ֱ��1��Nȫ�����ղ���ӡ��
//�����������У���һ����9���ڶ�����9�����֣���2 1 4 5 7 3 9 8 6
//��� 11 21 33 43 53 66 76 86 96
template<class T>
struct greater
{
	bool operator()(T& a, T& b)
	{
		return a >= b;
	}
};
#include <queue>
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	priority_queue<int, vector<int>, greater<int>> q;
	int min = 1;
	int k = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		q.push(arr[i]);
		if (arr[i] == min)//�������min��˵����ʱ�Ƿ���Ҫ��ģ���������
		{
			while (q.top() == min)
			{
				cout << k++ << " " << arr[i] << endl;
				min++;
				q.pop();
			}
		}
	}
	return 0;
}
#endif
#if 0
//����������
//Ҳ����һ��ʼ��1�����ӣ���������1�죬��������һ����һ�����ӣ�n����ж��ٸ�����
//1<=n<=90
#define MAXSIZE 90
int main()
{
	int n;
	vector<long long> arr(MAXSIZE);
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < MAXSIZE; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	while (cin >> n)
	{
		cout << arr[n - 1] << endl;
	}
	return 0;
}
#endif
#if 0
//��s�ַ�����t�ַ���һ�������˶��ٴ�
#include <string>
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int result = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)
		{
			result++;
			pos += t.size();
		}
		cout << result << endl;
	}
}
#endif
#if 0
//�����·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
//��һ��ʱ�����䣬������������ж���
//�ж��Ƿ�������
int leap_year(int year)//��������꣬����1�����򷵻�0
{
	return ((year % 4 != 0 && year % 100 == 0) || year % 400 == 0);
}
//2 3 5 7 11��������
//1 3 5 7 8 10 12����31��
int profit(int year)
{
	return 2 * 31 + 1 * 28 + leap_year(year) + 1 * 31 + 2 * 30 + 1 * 31 + 2 * 30 + 1 * 31 + 2 * 31 + 2 * 30 + 2 * 31 + 1 * 30 + 2 * 31;
}
bool isprime(int month)//�ж��Ƿ���������
{
	return month == 2 || month == 3 || month == 5 || month == 7 || month == 11;
}
//��ĳһ������һ��ĵڼ��죬���������
int profitOfthisyear(int year, int month, int day)
{
	if (!isprime(month))//�ж�������ǲ���������
		day *= 2;
	while (--month)
	{
		switch (month)
		{
			//�Ȳ�����������31����·�
			case 1:
			case 8:
			case 10:
			case 12:
				day += 62;
				break;
			//�Ȳ�����������30����·�
			case 4:
			case 6:
			case 9:
				day += 60;
				break;
			//������������31����·�
			case 3:
			case 5:
			case 7:
				day += 31;
				break;
			//������������30����·�
			case 11:
				day += 30;
				break;
			case 2:
				day += 28 + leap_year(year);
				break;
			default:
				;
		}
	}
	return day;
}
int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int sum = 0;//������
		sum += profit(year1) - profitOfthisyear(year1, month1, day1);//�������year1������year1��month1��day1��һ��֮���������
		sum += profitOfthisyear(year2, month2, day2);//�ټ��ϴ�year2���꿪ʼ��year2,month2,day2��һ�������
		//���������֮��͵õ��˴�year1,month1,day1��year2,month2,day2������
		if (year1 == year2)//�������һ����
			sum -= profit(year1);
		for (int i = year1 + 1; i < year2; ++i)
		{
			//�����м��ж�������ڼӼ��������
			sum += profit(i);
		}
		cout << sum << endl;
	}
	return 0;
}
#endif
#if 0
//�ֽ�����
//������������a���ֽ�����ɸ������ĳ˻���
//�� a = a1 �� a2 �� a3 �� ... �� an,���� 1 < a1 �� a2 �� a3 �� ...�� an,
//����a1��a2��...��an��Ϊ����,�ȸ���һ������a��������ֽ�������;
int main()
{
	int n;
	while (cin >> n)
	{
		printf("%d = ", n);
		for (int i = 2; i < sqrt(n); ++i)
		{
			while (n%i == 0 && n != i)//��n��������2��ʼ��ͬһ������ֱ��������
			{
				printf("%d* ", i);
				n /= i;
			}
		}
		printf("%d\n", n);//���һ��������
	}
	return 0;
}
#endif
//���ַ���ǰ������ɸ��ַ��Ƶ��ַ�����β��
//����һ��������������ַ�һ��һ���Ƶ�ĩβ
//�ȶ���һ����һ���ַ��Ƶ�ĩβ�ĺ���
void removech(string& s, int n)
{
	char ch = s[0];
	for (int i = 1; i < n; ++i)
	{
		s[i - 1] = s[i];//ȫ����ǰ��һ��λ�ã��ٽ�ch�ŵ���󼴿�
	}
	s[n - 1] = ch;
}
//Ȼ�������������Ҫ�ƶ����ַ��ĸ����μ���
void remove(string& s,int size,int m)//�ƶ�m���ַ�
{
	while (m--)
	{
		removech(s, size);
	}
}
//������������ʱ�临�Ӷ���O(mn),�������Ҫʹ��һ�ֽ���ʱ�临�Ӷȵķ���
//���Խ��ַ�����ΪҪ�ƶ����ַ��Ͳ����ƶ����ַ������֣��Ƚ������ֱַ�ת���ɵõ���Ȼ�������ַ�����ת
void reverseString(string& s, int start,int end)
{
	while (start < end)
	{
		char t = s[start];
		s[start] = s[end];
		s[end] = t;
		start++;
		end--;
	}
}
void reverse(string& s, int n,int m)//Ҫ�ƶ�mλ
{
	m %= n;//��ֹ����m>n�����
	reverseString(s, 0, m - 1);//�Ƚ������ֱַ�ת
	reverseString(s, m, n - 1);
	reverseString(s, 0, n - 1);//�����巴ת
}
int main()
{
	string s = "abcdefg";
	//remove(s, s.size(), 3);
	reverse(s, s.size(), 3);
	return 0;
}
