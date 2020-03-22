#if 0
//实现unique_ptr
namespace Daisy
{
	template<class T>
	class unique_ptr
	{
	private:
		T* _ptr;//外部传入的指针
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{
		}
		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
		//让智能指针具有指针特性
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//防拷贝
	private:
		//C++98
		//unique_ptr(const unique_ptr<T>&);
		//unique_ptr<T> opeartor = (const unique_ptr<T>&);
		//c++11
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T> opeartor = (const unique_ptr<T>&) = delate;
	};
}
int main()
{
	Daisy::unique_ptr<int> d1(new int);
	//Daisy::unique_ptr<int> d2(d1);//不能拷贝
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//实现shared_ptr
namespace Daisy
{
	template <class T>
	class shared_ptr
	{
	private:
		T* _ptr;
		int* _pCount;//整数指针
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (ptr)//如果外部传入一个资源
			{
				_pCount = new int(1);
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//解决浅拷贝方式：利用引用计数
		shared_ptr(const shared_ptr<T>& s)
			:_ptr(s._ptr)
			, _pCount(s._pCount)
		{
			if (_ptr)//如果此时资源存在，但是此时增加一个与源对象共享资源的拷贝对象
			{
				(*_pCount)++;
			}
		}
		shared_ptr<T> operator= (const shared_ptr<T>& s)
		{
			if (_ptr != s._ptr)//不是自己给自己赋值
			{
				release();//先释放原空间
				//让源内容指向赋值的内容
				_ptr = s._ptr;
				_pCount = s._pCount;
				if (_ptr)
					++(*_pCount);
			}
			return *this;
		}
		~shared_ptr()
		{
			release();
		}
	private:
		void release()
		{
			if (_ptr && --(*_pCount) == 0)
			{
				delete _ptr;
				delete _pCount;
			}
		}
	};
}
int main()
{
	Daisy::shared_ptr<int> d1(new int);
	Daisy::shared_ptr<int> d2(d1);
	Daisy::shared_ptr<int> d3 = d2;
	return 0;
}
#endif
//一场考试包含3道开放性题目，
//假设他们的难度从小到大分别为a, b, c，我们希望这3道题能满足下列条件：
//a＜ = b＜ = c
//b - a＜ = 10
//c - b＜ = 10
//所有出题人一共出了n道开放性题目,
//现在我们想把这n道题分布到若干场考试中（1场或多场，每道题都必须使用且只能用一次），
//然而由于上述条件的限制，可能有一些考试没法凑够3道题，因此出题人就需要多出一些适当难度的题目来让每场考试都达到要求。
//然而我们出题已经出得很累了，你能计算出我们最少还需要再出几道题吗？
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#if 0
int myCount(vector<int>& a, int n)
{
	vector<int> result;//保存满足条件的三个数
	sort(a.begin(), a.end());//保证第一个条件
	int count = 0;
	result.push_back(a[0]);
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] - a[i - 1] <= 10)//满足条件2 3
		{
			result.push_back(a[i]);
			if (result.size() == 3)//要进行下一个考场
			{
				result.clear();
				i++;
				if (i >= a.size())
					break;
				result.push_back(a[i]);//下一个考场开始、
			}
		}
		else
		{
			count = count + 3 - result.size();
			result.clear();
			result.push_back(a[i]);
		}
	}
	if (result.size() != 0)//说明还想要出题
		count = count + 3 - result.size();
	return count;
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		int r;
		cin >> r;
		arr.push_back(r);
	}
	int count = myCount(arr, n);
	cout << count << endl;
	return 0;
}
#endif
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int res = 0;
	int count = 1;
	for (int i = 1; i < n; i++){
		if (arr[i] - arr[i - 1] <= 10)
			count++;
		else
		{
			if (count % 3 != 0)
				res += (3 - (count % 3));
			count = 1;
		}
	}
	if (count % 3 != 0)
		res += (3 - (count % 3));
	cout << res << endl;
	return 0;
}