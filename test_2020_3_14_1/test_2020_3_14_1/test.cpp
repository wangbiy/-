#include <iostream>
using namespace std;
//����
//��������
//1.ֱ�Ӳ�������
void Insertsort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int k = arr[i];//���������Ԫ��
		int end = i - 1;//���������е����һ��Ԫ���±�
		while (end >= 0 && k < arr[end])//��ǰ������
		{
			arr[end + 1] = arr[end];//������
			end--;
		}
		//�ߵ�����˵�����Ԫ�ر�����������Ԫ��С��λ��
		arr[end + 1] = k;
	}
}
//2.ϣ������
void insertSortwithGap(int arr[], int size, int gap)
{
	for (int i = gap; i < size; ++i)
	{
		int k = arr[i];//���������Ԫ��
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
//ѡ������
//1.��ѡ������
void selectsort1(int arr[], int size)
{
	for (int i = 0; i < size; ++i)//��size��
	{
		int max = 0;//ÿ�μ�װ����һ����Ϊ���ıȽ�
		for (int j = 1; j < size - i; ++j)//��������
		{
			if (arr[j]>arr[max])
				max = j;
		}
		//���������ҵ����ģ��Ž��������䣬���������γɵ�����������ÿ�ε������������һ�����γɵ�
		swap(arr[max], arr[size - 1 - i]);
	}
}
void selectsort2(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;//��װÿ����С�Ķ��������������һ��
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[min]>arr[j])
				min = j;
		}
		//�ҵ����������С�ģ�������������һ������
		swap(arr[min], arr[i]);
	}
}
//2.������
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
	if (left >= size)//˵��������
		return;
	int max = left;
	if (right<size && arr[right]>arr[left])//�����
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
//��������
//1.��������
int partition1(int arr[], int left, int right)//hoare��
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
int partition2(int arr[], int left, int right)//�ڿӷ�
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
//��������ǵݹ�
#include <stack>
void quicksortNORHelp(int arr[], int left, int right)
{
	stack<int> s;
	//�ȶ����л���
	int index = partition1(arr, left, right);//�ֳ�������[left,index-1],index,������[index+1,right]
	//������
	if (index > left + 1)
	{
		s.push(0);//�ͽ���ջ
		s.push(index - 1);//�߽���ջ
	}
	//������
	if (index < right + 1)
	{
		s.push(index + 1);//�ͽ���ջ
		s.push(right);//�߽���ջ
	}
	while (!s.empty())
	{
		int end = s.top();//ȡ��������߽�
		s.pop();
		int start = s.top();//ȡ��������ͽ�
		s.pop();
		int pivotindex = partition1(arr, start, end);//����������л���
		if (pivotindex > start + 1)
		{
			//�������������
			s.push(0);//�ͽ���ջ
			s.push(pivotindex - 1);//�߽���ջ
		}
		if (pivotindex < end - 1)
		{
			//�������������
			s.push(pivotindex + 1);//�ͽ�
			s.push(end);//�߽�
		}
	}
}
void quicksortNOR(int arr[], int size)
{
	quicksortNORHelp(arr, 0, size - 1);
}
//2.ð������
void bubblesort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)//�Ƚϵ�����
	{
		bool flag = 1;//��ʾ��ǰ���ý��н���
		for (int j = 0; j < size - 1 - i; j++)//��ʾ�Ƚ�Ԫ�صĸ�����ÿ�ζ�����һ�˱Ƚ���һ������Ϊ֮ǰ���Ѿ��ȹ���
		{
			if (arr[j]>arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)//��ʾ������ģ����ñȽ�
			break;
	}
}
//�鲢����
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
	//�����left
	memcpy(arr + left, tmp + left, (right - left)*sizeof(arr[0]));
}
void _MergeSort(int arr[], int left, int right, int* tmp)
{
	if (left >= right-1)//���ε�ÿ����ʣһ��һ��Ԫ��
		return;
	int mid = left + ((right - left) >> 1);
	//�Ƚ��еݹ���з��Σ�ֱ��С���������ݸ���С�ڵ���1
	_MergeSort(arr, left, mid, tmp);//��߹鲢����ʹ������
	_MergeSort(arr, mid, right, tmp);//�ұ߹鲢����ʹ������
	MergeData(arr, left, mid, right, tmp);//�鲢������������
}
void MergeSort(int arr[], int size)
{
	int* tmp = (int*)malloc(size*sizeof(arr[0]));
	_MergeSort(arr, 0, size,tmp);
	free(tmp);
}
//��������
void CountSort(int arr[], int size)
{
	//�������ݷ�Χ
	int minValue = arr[0];
	int maxValue = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i]>maxValue)
			maxValue = arr[i];
		if (arr[i] < minValue)
			minValue = arr[i];
	}
	int range = maxValue - minValue + 1;//���ݸ���
	int* tmp = (int*)malloc(sizeof(int)*range);
	if (tmp == nullptr)
		return;
	memset(tmp, 0, sizeof(int)*range);
	for (int i = 0; i < size; ++i)
	{
		tmp[arr[i] - minValue]++;//һ��Ҫ��ȥminValue����Ϊ������9900��10000��ֻ��100����������ʹ�õ��ǹ�ϣ��˼�룬���Ƿ�Χȴ��0��100�������޷�������ִ���
	}
	//�����ݽ��л���
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