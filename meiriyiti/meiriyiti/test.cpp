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
#if 0
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
#endif
#if 0
//���ʷ�ת����
#include <string>
void reverse(string& s, int start, int end)//���巴ת
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
void reversestring(string& s, int n)
{
	//�����巴ת
	reverse(s, 0, n - 1);
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == ' ')
		{
			end = i;
			reverse(s, start, end);
			start = end + 1;
		}
	}
}
int main()
{
	string s = "I am a student";
	reversestring(s, s.size());
}
#endif
#if 0
//���ݿ����ӳ�����
//Ҳ�����������һ�����Ӿʹ���һ�����ӣ��õ��������������
//��������  6 A connect��A disconnect��B connect��C connect��B disconnect��C disconnect
//���2
//�����������Ҫ��������֤���еĶ���ִ��
#include <set>
#include <string>
int main()
{
	int n;
	while (cin >> n)
	{
		string id, mes;
		set<string> pool;
		int MaxSize = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> id >> mes;
			if (mes == "connect")
				pool.insert(id);
			else if (mes == "disconnect")
				pool.erase(id);
			int size = pool.size();
			MaxSize = MaxSize>size ? MaxSize : size;
		}
		cout << MaxSize << endl;
	}
	return 0;
}
#endif
#if 0
//ʵ��mkdir -p���ܣ����������������/usr/local /usr/local/test,�Ͳ����ٴ����ڶ���/usr/local��
//������������ַ�����ͬ��Ҳ�����ٴ���һ�Σ������ͬ�Ҳ����Ӵ��Ĺ�ϵ�����ܴ���
#include <vector>
#include <string>
#include <algorithm>
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> ret(n);//����ÿ���ַ���
		vector<bool> flag(n, true);//��ʾ�����ַ�����ǰ�����һ���ܲ��ܱ�����
		for (int i = 0; i < n; ++i)
		{
			cin >> ret[i];
		}
		sort(ret.begin(), ret.end());//�����Ƶ��ַ�������һ��
		for (int i = 0; i < ret.size() - 1; ++i)//�����ַ�����������ж�
		{
			if (ret[i] == ret[i + 1])//�����ַ������
				flag[i] = false;
			else if (ret[i].size() < ret[i + 1].size() && ret[i] == ret[i + 1].substr(0, ret[i].size()) && ret[i + 1][ret[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i < ret.size(); ++i)
		{
			if (flag[i] == true)
				cout << "mkdir -p " << ret[i] << endl;
		}
		cout << endl;
	}
	return 0;
}
#endif
//�ַ����İ���
//Ҳ�����ж�a�ַ������Ƿ����B�ַ���
#if 0
//����1.������
#include <string>
bool contain1(string a, string b)
{
	for (int i = 0; i < b.size(); ++i)
	{
		int j;
		for (j = 0; j < a.size() && a[j] != b[i]; ++j)
			;//һֱ�ҿ�a����û�к�b��ǰ�ַ���ͬ��
		//�ҵ���˵����a���ҵ���b���ַ���ͬ����
		if (j>a.size())
			return false;
	}
	//����˵������
	return true;
}
#endif
#if 0
//���Ǳ�������ʱ�临�Ӷ���O(a�ĳ���*b�ĳ��ȣ���ʱ�临�ӶȺܴ�������Ǳ���Ҫ�����Ż�
//���Էֱ�������ַ�����������Ȼ�������ѯ
#include <algorithm>
bool contain2(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0, j = 0; j < b.size();)
	{
		while (i < a.size() && a[i] < b[j])//Ҫ��a��ǰ���ַ�С��b��ǰ���ַ�
			i++;
		if (i>a.size() && a[i]>b[j])//˵����a��һ��������b
			return false;
		j++;
	}
	return true;
}
int main()
{
	string a = "abcabc";
	string b = "abc";
	bool flag = contain2(a, b);

	return 0;
}
#endif
#if 0
#include <string>
#include <algorithm>
//�����������
//Ҳ�����ַ�����1��abcdaf,�ַ���2��acbcf:��ʱ������������о���abcf
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	//�Ƚ���0�к͵�0�ж���ʼ��Ϊ0
	for (int i = 0; i < n + 1; ++i)
		dp[i][0] = 0;
	for (int i = 0; i < m + 1; ++i)
		dp[0][i] = 0;
	//Ȼ�����ʵ��
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			if (s1[j - 1] == s2[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	//�������
	cout << dp[n][m] << endl;
	return 0;
}
#endif
#if 0
//ƹ��������⣬Ҳ���ǿ�A������Ƿ����B����������������
#include <map>
//����ʹ������map�ֱ�A��Ԫ�غ�B��Ԫ�� ��������Ȼ����A��ͬ����û�ж�ӦB
#include <string>
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		bool flag = true;
		map<char, int> m1, m2;//��������map�ֱ�A��B���ַ����ȥ
		for (auto e : A)
		{
			m1[e]++;
		}
		for (auto e : B)
		{
			m2[e]++;
		}
		//Ȼ����m2�б�����m1��ͬ�ֽ��жԱ�
		for (auto it = m2.begin(); it != m2.end(); ++it)
		{
			if (m1[it->first]<it->second)
				//˵��������
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#endif
#if 0
//�����ֵܵ�������
//�ֵܵ��ʾ�������ҵ��ʳ�����ͬ��˳��ͬ�ĵ���
//�������շ��ص����ֵ����е�m���ֵܵ��ʣ��ҷ����ֵܵ��ʸ���
#include <algorithm>
#include <vector>
#include <string>
bool isBrother(string s1, string s2)
{
	if (s1.size() == s2.size())
	{
		if (s1 == s2)
			return false;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2)
			return true;
	}
	return false;
}
int main()
{
	int n;//n������
	while (cin >> n)
	{
		string word;//Ҫ������ҵĵ���
		string s;//��������m���ֵܵ���
		vector<string> arr(n);//�ֵ䣬��������ĵ���
		int m;//��ʾ��m���ֵܵ���
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		//����Ҫ�����ֵ��������m���ֵܵ��ʣ����������
		sort(arr.begin(), arr.end());
		cin >> word;
		cin >> m;
		int count = 0;//ͳ���ֵܵ��ʸ���
		for (int i = 0; i < n; ++i)
		{
			if (isBrother(word, arr[i]))
				count++;
			if (count == m)
				s = arr[i];
		}
		if (!arr.empty())
			cout << count << endl;
		if (count >= m)
			cout << s << endl;
	}
	return 0;
}
#endif
#if 0
//�����������������ǽ�������hello_worldתΪhelloWorld
//��˱����ַ���������_������ѭ������ִ�У�ֻҪ��ǰ�ַ���ǰһ����'_'���ͶԸ��ַ�����ת��
#include <string>
int main()
{
	string c_str;
	while (cin >> c_str)
	{
		for (int i = 0; i < c_str.size(); ++i)
		{
			if (c_str[i] == '_')
				continue;
			if (i >0 && c_str[i - 1] == '_')
				cout << (char)toupper(c_str[i]);
			else
				cout << c_str[i];
		}
		cout << endl;
	}
	return 0;
}
#endif
#if 0
//���ʵ�ת
//���������Ǵ�д����Сд��ĸ���ַ�ʱ�������Ƿָ�������תΪ�ո�
//����ж���ָ�����תΪһ���ո񼴿�
#include <string>
#include <sstream>
#include <vector>
int main()
{
	string str;//����istringstream���ս����ַ���
	string s;//������ַ���
	vector<string> arr;//�����зֵ��ַ���
	while (getline(cin,s))
	{
		istringstream ss(s);//��s������ȥ��ȡ�ַ�������s����"hello world",����������hello world
		while (ss >> str)//�����ַ�֮�����str��
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
				{
					str[i] = ' ';
				}
			}
			istringstream temp(str);
			while (temp >> str)
				arr.push_back(str);
		}
		for (auto it = arr.rbegin(); it != arr.rend() - 1; ++it)
		{
			cout << *it << " ";
		}
		cout << arr[0];
		cout << endl;
	}
	return 0;
}
#endif
//�ַ�����ȫ����
//��abc�������г�����������
//abc acb bac bca cab cba
//���õݹ�ķ�ʽ��ʵ�� 
//��a�̶��ڵ�һλ���Ժ����bc����������
//��b�̶��ڵ�һλ���Ժ����ac����������
//��c�̶��ڵ�һλ���Ժ����ab����������
#include <string>
void calcallpermutation(string& str, int from, int to)
{
	if (from == to)//˵���Ѿ��õ�ȫ���������ˣ���������
	{
		for (int i = 0; i <= to; ++i)
		{
			cout << str[i];
		}
		cout << endl;
	}
	else
	{
		for (int j = from; j <= to; ++j)
		{
			swap(str[j], str[from]);//��һ�ν�����Ϊ��Ҫÿһ��Ԫ�ؿ�����Ϊ��һ��
			calcallpermutation(str, from + 1, to);//�Ե�һ������ļ�������ȫ����
			swap(str[j], str[from]);//ÿһ��һ��Ԫ����Ϊ��һ��֮����������У�Ҫ���и�λ�Է��Ժ���Ĳ���Ӱ��
		}
	}
}
void perm(string& str)
{
	int from = 0;
	int to = str.size() - 1;
	calcallpermutation(str, from, to);
}
//����ת��������
string intToRoman(int num)
{
	char* arr[4][10] = {
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM", "MMM" }
	};//�Ƚ����е�ö�٣�Ȼ��ͨ���������������ĸ�λ��ʮλ����λ�Լ�ǧλ��������������е�λ�ö�Ӧ
	string result;
	result.append(arr[3][num / 1000]);
	result.append(arr[2][num / 100 % 10]);
	result.append(arr[1][num / 10 % 10]);
	result.append(arr[0][num % 10]);
	return result;
}
//��������ת����
int help(char ch)//�Ƚ��ַ������е�����������תΪ����
{
	int result;
	switch (ch)
	{
	case 'I':
		result = 1;
		break;
	case 'V':
		result = 5;
		break;
	case 'X':
		result = 10;
		break;
	case 'L':
		result = 50;
		break;
	case 'C':
		result = 100;
		break;
	case 'D':
		result = 500;
		break;
	case 'M':
		result = 1000;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}
int romanToInt(string s)
{
	int n = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (i < len)
		{
			int j = i + 1;
			if (help(s[i]) < help(s[j]))//����������IV��������ʽ
			{
				n += (help(s[j]) - help(s[i]));
				i++;
			}
			else//����IV��������ʽ��ֱ�Ӽӵ�ǰ�������ּ���
				n += help(s[i]);
		}
		else//˵�������ַ���ĩβ��������������ʽ
			n += help(s[i]);
	}
	return n;
}
//�������(��Ѷ2017���ʵϰ�������⣩
//����һ���ַ���s������Դ���ɾ��һЩ�ַ���
//ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�����
//�����ȿ��������ַ���s���õ�s0��Ȼ��s0��ת�������ߵ�����������еĳ��ȣ�������ַ������ȼ�ȥ������
#include <string>
#include <vector>
#include <algorithm>
int max(int a, int b)
{
	return a > b ? a : b;
}
int Delete(string s)
{
	string s0(s);
	reverse(s0.begin(), s0.end());
	int len = s.size();
	vector<vector<int>> tmp(len + 1, vector<int>(len + 1));
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (s0[i] == s[j])
				tmp[i + 1][j + 1] = tmp[i][j] + 1;
			else
				tmp[i + 1][j + 1] = max(tmp[i + 1][j], tmp[i][j + 1]);
		}
	}
	return len - tmp[len][len];
}
//��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬
//�����ַ������λ�ò��䣬�Ҳ����������Ŀռ�(��Ѷ�����⣩
string func(string& s)
{
	for (int i = 0; i < s.size(); ++i)//һ������size��
	{
		for (int j = 0; j < s.size() - 1; ++j)
		{
			if (s[j] <= 'A' && s[j] >= 'Z' && s[j + 1] <= 'a' && s[j + 1] >= 'z')//�����ǰ�Ǵ�д��һ����Сд����������
			{
				char t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
	return s;
}

int main()
{
	string str = "abc";
	perm(str);
	string result = intToRoman(122);
	cout << result << endl;

	int ret = romanToInt("LVIII");
	cout << ret << endl;

	string s = "abcda";
	ret = Delete(s);
	cout << "����Ҫɾ��" << ret << "���ַ�" << endl;

	s = "AkleBiCeiLD";
	result=func(s);
	cout << result << endl;
	return 0;
}


