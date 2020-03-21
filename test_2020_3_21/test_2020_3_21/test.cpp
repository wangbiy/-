#include <iostream>
using namespace std;
//快速排序
int partition(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)
			begin++;
		while (begin < end && arr[end] >= pivot)
			end--;
		swap(arr[begin], arr[end]);
	}
	swap(arr[begin], pivot);
	return begin;
}
void _quicksort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int pivotindex = partition(arr, left, right);
	_quicksort(arr, left, pivotindex - 1);
	_quicksort(arr, pivotindex + 1, right);
}
void quicksort(int* arr, int size)
{
	return _quicksort(arr, 0, size - 1);
}
//合并两个有序链表成为一个有序链表
void merge(Node* pHead1, Node* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	Node* result = nullptr;
	Node* last = nullptr;
	Node* c1 = pHead1;
	Node* c2 = pHead2;
	while (c1 != nullptr && c2 != nullptr)
	{
		if (c1->val <= c2->val)
		{
			Node* next = c1->next;
			c1->next = nullptr;
			if (result == nullptr)
			{
				result = c1;
			}
			else
				last->next = c1;
			last = c1;
			c1 = next;
		}
		else
		{
			Node* next = c2->next;
			c2->next = nullptr;
			if (result == nullptr)
				result = c2;
			else
				last->next = c2;
			last = c2;
			c2 = next;
		}
	}
	if (c1 != nullptr)
		last->next = c1;
	if (c2 != nullptr)
		last->c2;
	return result;
}