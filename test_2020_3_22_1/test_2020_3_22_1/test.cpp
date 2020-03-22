#if 0
//ʵ��unique_ptr
namespace Daisy
{
	template<class T>
	class unique_ptr
	{
	private:
		T* _ptr;//�ⲿ�����ָ��
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
		//������ָ�����ָ������
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//������
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
	//Daisy::unique_ptr<int> d2(d1);//���ܿ���
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//ʵ��shared_ptr
namespace Daisy
{
	template <class T>
	class shared_ptr
	{
	private:
		T* _ptr;
		int* _pCount;//����ָ��
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (ptr)//����ⲿ����һ����Դ
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
		//���ǳ������ʽ���������ü���
		shared_ptr(const shared_ptr<T>& s)
			:_ptr(s._ptr)
			, _pCount(s._pCount)
		{
			if (_ptr)//�����ʱ��Դ���ڣ����Ǵ�ʱ����һ����Դ��������Դ�Ŀ�������
			{
				(*_pCount)++;
			}
		}
		shared_ptr<T> operator= (const shared_ptr<T>& s)
		{
			if (_ptr != s._ptr)//�����Լ����Լ���ֵ
			{
				release();//���ͷ�ԭ�ռ�
				//��Դ����ָ��ֵ������
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
//һ�����԰���3����������Ŀ��
//�������ǵ��Ѷȴ�С����ֱ�Ϊa, b, c������ϣ����3��������������������
//a�� = b�� = c
//b - a�� = 10
//c - b�� = 10
//���г�����һ������n����������Ŀ,
//�������������n����ֲ������ɳ������У�1����ೡ��ÿ���ⶼ����ʹ����ֻ����һ�Σ���
//Ȼ�������������������ƣ�������һЩ����û���չ�3���⣬��˳����˾���Ҫ���һЩ�ʵ��Ѷȵ���Ŀ����ÿ�����Զ��ﵽҪ��
//Ȼ�����ǳ����Ѿ����ú����ˣ����ܼ�����������ٻ���Ҫ�ٳ���������
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#if 0
int myCount(vector<int>& a, int n)
{
	vector<int> result;//��������������������
	sort(a.begin(), a.end());//��֤��һ������
	int count = 0;
	result.push_back(a[0]);
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] - a[i - 1] <= 10)//��������2 3
		{
			result.push_back(a[i]);
			if (result.size() == 3)//Ҫ������һ������
			{
				result.clear();
				i++;
				if (i >= a.size())
					break;
				result.push_back(a[i]);//��һ��������ʼ��
			}
		}
		else
		{
			count = count + 3 - result.size();
			result.clear();
			result.push_back(a[i]);
		}
	}
	if (result.size() != 0)//˵������Ҫ����
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