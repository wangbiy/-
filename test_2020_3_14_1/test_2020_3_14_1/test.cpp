#include <iostream>
using namespace std;
//排序
//插入排序
//1.直接插入排序
void Insertsort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int k = arr[i];//保存遍历的元素
		int end = i - 1;//已排序序列的最后一个元素下标
		while (end >= 0 && k < arr[end])//向前继续找
		{
			arr[end + 1] = arr[end];//向后搬移
			end--;
		}
		//走到这里说明这个元素比已排序序列元素小的位置
		arr[end + 1] = k;
	}
}
//2.希尔排序
void insertSortwithGap(int arr[], int size, int gap)
{
	for (int i = gap; i < size; ++i)
	{
		int k = arr[i];//保存遍历的元素
		int end = i - gap;
		while (end >= 0 && k < arr[end])
		{
			arr[end + gap] = arr[end];
			end -= gap;
		}
		arr[end + gap] = k;
	}
}
void shellsort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		insertSortwithGap(arr,size,gap);
		if (gap == 1)
			break;
	}
}
//选择排序
//1.简单选择排序
void selectsort1(int arr[], int size)
{
	for (int i = 0; i < size; ++i)//比size次
	{
		int max = 0;//每次假装将第一个作为最大的比较
		for (int j = 1; j < size - i; ++j)//无序区间
		{
			if (arr[j]>arr[max])
				max = j;
		}
		//无序区间找到最大的，放进有序区间，我们这里形成的有序区间是每次的无序区间最后一个来形成的
		swap(arr[max], arr[size - 1 - i]);
	}
}
void selectsort2(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;//假装每次最小的都是有序序列最后一个
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[min]>arr[j])
				min = j;
		}
		//找到无序队列最小的，与有序队列最后一个交换
		swap(arr[min], arr[i]);
	}
}
//2.堆排序
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void heapify(int arr[], int size, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size)//说明超过了
		return;
	int max = left;
	if (right<size && arr[right]>arr[left])//建大堆
		max = right;
	if (arr[index] >= arr[max])
		return;
	swap(arr + index, arr + max);
	heapify(arr, size, max);
}
void creatHeap(int arr[], int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify(arr, size, i);
	}
}
void HeapSort(int arr[], int size)
{
	creatHeap(arr, size);
	for (int i = 0; i < size; ++i)
	{
		swap(arr, arr + size - 1 - i);
		heapify(arr, size - i - 1, 0);
	}
}
//交换排序
//1.快速排序
int partition1(int arr[], int left, int right)//hoare法
{
	int pivot = arr[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)
			begin++;
		while (begin<end && arr[end]>=pivot)
			end--;
		swap(arr + begin, arr + end);
	}
	swap(arr[begin], pivot);
	return begin;
}
int partition2(int arr[], int left, int right)//挖坑法
{
	int pivot = arr[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)
			begin++;
		arr[end] = arr[begin];
		while (begin<end && arr[end]>=pivot)
			end--;
		arr[begin] = arr[end];
	}
	arr[begin] = pivot;
	return begin;
}
void QuickSortInternal(int arr[], int left,int right)
{
	if (left >= right)
		return;
	int pivot = partition1(arr, left, right);
	QuickSortInternal(arr, left, pivot - 1);
	QuickSortInternal(arr, pivot + 1, right);
}
void quickSort(int arr[], int size)
{
	QuickSortInternal(arr, 0, size - 1);
}
//快速排序非递归
#include <stack>
void quicksortNORHelp(int arr[], int left, int right)
{
	stack<int> s;
	//先对序列划分
	int index = partition1(arr, left, right);//分成左区间[left,index-1],index,右区间[index+1,right]
	//左区间
	if (index > left + 1)
	{
		s.push(0);//低界入栈
		s.push(index - 1);//高界入栈
	}
	//右区间
	if (index < right + 1)
	{
		s.push(index + 1);//低界入栈
		s.push(right);//高界入栈
	}
	while (!s.empty())
	{
		int end = s.top();//取出右区间高界
		s.pop();
		int start = s.top();//取出右区间低界
		s.pop();
		int pivotindex = partition1(arr, start, end);//对右区间进行划分
		if (pivotindex > start + 1)
		{
			//右区间的左区间
			s.push(0);//低界入栈
			s.push(pivotindex - 1);//高界入栈
		}
		if (pivotindex < end - 1)
		{
			//右区间的右区间
			s.push(pivotindex + 1);//低界
			s.push(end);//高界
		}
	}
}
void quicksortNOR(int arr[], int size)
{
	quicksortNORHelp(arr, 0, size - 1);
}
//2.冒泡排序
void bubblesort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)//比较的趟数
	{
		bool flag = 1;//表示当前不用进行交换
		for (int j = 0; j < size - 1 - i; j++)//表示比较元素的个数，每次都比上一趟比较少一个，因为之前的已经比过了
		{
			if (arr[j]>arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)//表示是有序的，不用比较
			break;
	}
}
//归并排序
void MergeData(int arr[], int left, int mid, int right, int* tmp)
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
	//必须加left
	memcpy(arr + left, tmp + left, (right - left)*sizeof(arr[0]));
}
void _MergeSort(int arr[], int left, int right, int* tmp)
{
	if (left >= right-1)//分治到每部分剩一个一个元素
		return;
	int mid = left + ((right - left) >> 1);
	//先进行递归进行分治，直到小区间内数据个数小于等于1
	_MergeSort(arr, left, mid, tmp);//左边归并排序，使得有序
	_MergeSort(arr, mid, right, tmp);//右边归并排序，使得有序
	MergeData(arr, left, mid, right, tmp);//归并两个有序数组
}
void MergeSort(int arr[], int size)
{
	int* tmp = (int*)malloc(size*sizeof(arr[0]));
	_MergeSort(arr, 0, size,tmp);
	free(tmp);
}
//计数排序
void CountSort(int arr[], int size)
{
	//先找数据范围
	int minValue = arr[0];
	int maxValue = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i]>maxValue)
			maxValue = arr[i];
		if (arr[i] < minValue)
			minValue = arr[i];
	}
	int range = maxValue - minValue + 1;//数据个数
	int* tmp = (int*)malloc(sizeof(int)*range);
	if (tmp == nullptr)
		return;
	memset(tmp, 0, sizeof(int)*range);
	for (int i = 0; i < size; ++i)
	{
		tmp[arr[i] - minValue]++;//一定要减去minValue，因为可能是9900到10000，只有100个数，这里使用的是哈希的思想，但是范围却是0到100，根本无法计算出现次数
	}
	//对数据进行回收
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		int count = tmp[i];
		while (count--)
		{
			arr[index++] = i + minValue;
		}
	}
	free(tmp);
}
void print(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 1, 0, 2, 3, 4, 7, 5, 6, 10, 9, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int input = 0;
	cout << "Please select:";
	cin >> input;
	switch (input)
	{
	case 1:
		Insertsort(arr, size);
		print(arr, size);
		break;
	case 2:
		shellsort(arr, size);
		print(arr, size);
		break;
	case 3:
		selectsort1(arr, size);
		print(arr, size);
		break;
	case 4:
		selectsort2(arr, size);
		print(arr, size);
		break;
	case 5:
		HeapSort(arr, size);
		print(arr, size);
		break;
	case 6:
		quickSort(arr, size);
		print(arr, size);
		break;
	case 7:
		quicksortNOR(arr, size);
		print(arr, size);
		break;
	case 8:
		bubblesort(arr, size);
		print(arr, size);
		break;
	case 9:
		MergeSort(arr, size);
		print(arr, size);
		break;
	}
	int arr1[] = { 999, 999, 999, 998, 998, 990 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	CountSort(arr1, size1);
	print(arr1, size1);
	return 0;
}