#include <iostream>
using namespace std;
//ֱ�Ӳ�������
void insertsort(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int k = arr[i];
		int end = i - 1;//�����������һ��Ԫ���±�
		while (end >= 0 && k < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = k;
	}
}
//ϣ������
void shellsortwithgap(int* arr, int size, int gap)
{
	for (int i = gap; i < size; ++i)
	{
		int k = arr[i];
		int end = i - gap;
		while (end >= 0 && k < arr[end])
		{
			arr[end + gap] = arr[end];
			end -= gap;
		}
		arr[end + gap] = k;
	}	
}
void shellsort(int* arr, int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		shellsortwithgap(arr, size, gap);
		if(gap == 1)
			break;
	}
}
//��ѡ������
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void selectsort1(int* arr, int size)//���������������������������һ��Ԫ�ؽ���
{
	for (int i = 0; i < size; ++i)//һ����size��
	{
		int max = 0;
		for (int j = 1; j < size - i; ++j)//ÿһ������������һ��������Ϊ�Ѿ��������ҵ������ķ������������䣬����������ǰ�ƽ�
		{
			if (arr[j]>arr[max])
				max = j;
		}
		swap(arr[max], arr[size - 1 - i]);
	}
}
void selectsort2(int* arr, int size)//��������������С���������������һ�����н�����������������ƽ�����������ÿ�μ���һ��Ԫ��
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}
//������
//�����򽨴��
void heapify(int* arr, int size, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size)
		return;
	int max = left;//�ȼ�������������
	if (right<size && arr[right]>arr[max])
		max = right;
	if (arr[index] >= arr[max])
		return;
	swap(arr[max], arr[index]);
	heapify(arr, size, max);//�������µ���
}
void createheap(int* arr, int size)
{
	//�����һ����Ҷ�ӽ�㿪ʼ
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify(arr, size, i);
	}
}
//������
void heapsort(int* arr, int size)
{
	createheap(arr, size);//�����
	for (int i = 0; i < size; ++i)//����size��
	{
		//�����Ѷ�Ԫ�������һ��Ҷ�ӽ��
		swap(arr[0], arr[size - 1 - i]);
		heapify(arr, size - 1 - i, 0);//��0���¿�ʼ���µ���
	}
}
//��������
int partition(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = arr[end];//��׼ֵ
	while (begin < end)
	{
		while (begin < end && arr[begin] < pivot)
			begin++;
		while (begin<end && arr[end] > pivot)
			end--;
		//��������˵��begin���ڵ�Ԫ�رȻ�׼ֵ�����end���ڵ�Ԫ�رȻ�׼ֵС
		swap(arr[begin], arr[end]);
	}
	swap(arr[begin], pivot);
	return begin;
}
void _quicksort(int* arr, int left, int right)
{
	if (left >= right)//˵���Ѿ��������
		return;
	int pivotindex = partition(arr, left, right);//�����廮��
	//�Ի�׼ֵ��ߵĺ��ұߵĽ��еݹ������������
	_quicksort(arr, left, pivotindex - 1);
	_quicksort(arr, pivotindex + 1, right);
}
void quicksort(int* arr, int size)
{
	_quicksort(arr, 0, size - 1);
}
//�鲢����
//�Ƚ��з��Σ��Ƚ��������������Ȼ��ʹ�����жμ�����Ȼ��ϲ�
void Mergedata(int* arr, int left, int mid, int right, int* tmp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	while (begin1 < end1)
		tmp[index++] = arr[begin1++];
	while (begin2 < end2)
		tmp[index++] = arr[begin2++];
	//��tmp�еĿ�����arr��,���������Ǻϲ�������������У������Ա�����arr+left��tmp+left
	memcpy(arr + left, tmp + left, (right - left)*sizeof(arr[0]));
}
void _Mergesort(int* arr, int left, int right, int* tmp)
{
	if (left >= right - 1)//˵���Ѿ����ε�ʣһ��
		return;
	int mid = left + ((right - left) >> 1);
	_Mergesort(arr, left, mid, tmp);
	_Mergesort(arr, mid, right, tmp);
	//�ϲ�����������
	Mergedata(arr, left, mid, right, tmp);
}
void mergesort(int* arr, int size)
{
	int* tmp = (int*)malloc(sizeof(arr[0])*size);
	if (tmp == nullptr)
		return;
	_Mergesort(arr, 0, size - 1, tmp);
	free(tmp);
}
//ð������
void bubblesort(int* arr, int size)
{
	for (int i = 0; i < size; ++i)//����
	{
		int flag = 0;
		for (int j = 0; j < size - 1 -i; ++j)//�Ƚϴ���
		{
			if (arr[j]>arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//˵������
			break;
	}
}
void print(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 4, 5, 2, 3, 1, 6, 10, 7, 9, 18 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//insertsort(arr, size);
	//shellsort(arr, size);
	//selectsort1(arr, size);
	//selectsort2(arr, size);
	//heapsort(arr, size);
	//quicksort(arr, size);
	//mergesort(arr, size);
	bubblesort(arr, size);
	print(arr, size);
	return 0;
}