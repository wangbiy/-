#include <iostream>
using namespace std;
//直接插入排序
void insertsort(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int k = arr[i];
		int end = i - 1;//有序区间最后一个元素下标
		while (end >= 0 && k < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = k;
	}
}
//希尔排序
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
//简单选择排序
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void selectsort1(int* arr, int size)//在无序区间找最大的与有序区间第一个元素交换
{
	for (int i = 0; i < size; ++i)//一共找size次
	{
		int max = 0;
		for (int j = 1; j < size - i; ++j)//每一次无序区间少一个数，因为已经将本次找到的最大的放在了有序区间，有序区间向前推进
		{
			if (arr[j]>arr[max])
				max = j;
		}
		swap(arr[max], arr[size - 1 - i]);
	}
}
void selectsort2(int* arr, int size)//在无序区间找最小的与有序区间最后一个进行交换，有序区间向后推进，无序区间每次减少一个元素
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
//堆排序
//排升序建大堆
void heapify(int* arr, int size, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size)
		return;
	int max = left;//先假设最大的是左孩子
	if (right<size && arr[right]>arr[max])
		max = right;
	if (arr[index] >= arr[max])
		return;
	swap(arr[max], arr[index]);
	heapify(arr, size, max);//继续向下调整
}
void createheap(int* arr, int size)
{
	//从最后一个非叶子结点开始
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify(arr, size, i);
	}
}
//堆排序
void heapsort(int* arr, int size)
{
	createheap(arr, size);//建大堆
	for (int i = 0; i < size; ++i)//交换size次
	{
		//交换堆顶元素与最后一个叶子结点
		swap(arr[0], arr[size - 1 - i]);
		heapify(arr, size - 1 - i, 0);//从0重新开始向下调整
	}
}
//快速排序
int partition(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = arr[end];//基准值
	while (begin < end)
	{
		while (begin < end && arr[begin] < pivot)
			begin++;
		while (begin<end && arr[end] > pivot)
			end--;
		//到达这里说明begin所在的元素比基准值大或者end所在的元素比基准值小
		swap(arr[begin], arr[end]);
	}
	swap(arr[begin], pivot);
	return begin;
}
void _quicksort(int* arr, int left, int right)
{
	if (left >= right)//说明已经划分完毕
		return;
	int pivotindex = partition(arr, left, right);//先整体划分
	//对基准值左边的和右边的进行递归操作继续划分
	_quicksort(arr, left, pivotindex - 1);
	_quicksort(arr, pivotindex + 1, right);
}
void quicksort(int* arr, int size)
{
	_quicksort(arr, 0, size - 1);
}
//归并排序
//先进行分治，先将多个子序列有序，然后使子序列段间有序，然后合并
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
	//将tmp中的拷贝到arr中,由于我们是合并多个有序子序列，，所以必须是arr+left和tmp+left
	memcpy(arr + left, tmp + left, (right - left)*sizeof(arr[0]));
}
void _Mergesort(int* arr, int left, int right, int* tmp)
{
	if (left >= right - 1)//说明已经分治到剩一个
		return;
	int mid = left + ((right - left) >> 1);
	_Mergesort(arr, left, mid, tmp);
	_Mergesort(arr, mid, right, tmp);
	//合并有序子序列
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
//冒泡排序
void bubblesort(int* arr, int size)
{
	for (int i = 0; i < size; ++i)//趟数
	{
		int flag = 0;
		for (int j = 0; j < size - 1 -i; ++j)//比较次数
		{
			if (arr[j]>arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//说明有序
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