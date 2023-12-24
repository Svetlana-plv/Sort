#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "Sort.h"
#include "Function.h"

void bubble_sort(int* arr, int n, int comp()) {
	for (int i = 0; i < n; i++) {
		int unordered = 1;
		for (int j = 0; j < n - 1 - i; j++) {
			if (comp(arr[j],arr[j + 1])) {
				swap(&arr[j], &arr[j + 1]);
				unordered = 0;
			}
		}
		if (unordered) break;
	}
}

void insert_sort(int* arr, int n, int comp()) {
	for (int i = 0; i < n - 1; i++) {
		int key = arr [i + 1];
		for (int j = i; j >= 0; j--) {
			if (comp(arr[j], key))
				swap(&arr[j], &arr[j + 1]);
			else break;
		}
	}
}

void select_sort(int* arr, int n, int comp()) {
	for (int i = 0; i < n - 1; i++) {
		int min_ind = i;
		for (int j = i; j<n; j++) {
			if (comp(arr[min_ind], arr[j]))
				min_ind = j;
		}
		swap(&arr[i], &arr[min_ind]);
	}
}

void merge_sort(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	if (left >= right)
		return;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);
	merge_array(arr, left, mid, right);
}
// вспомогательные массивы инициализируются внутри функции
void merge_array(int* arr, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L;
	int* R;
	L = (int*)malloc(n1 * sizeof(int));
	R = (int*)malloc(n2 * sizeof(int));
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
	free(L);
	free(R);
}

void merge_sort_2(int* arr, int* tmp, int left, int right) { 
	int mid = (left + right) / 2;
	if (left >= right)
		return;
	merge_sort_2(arr, tmp, left, mid);
	merge_sort_2(arr, tmp, mid + 1, right);
	merge_array_2(arr, tmp, left, mid, right);
}
// вспомогательный массив передается в функцию
void merge_array_2(int* arr, int* tmp, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = n1 + right - mid;
	for (i = 0; i < n1; i++)
		tmp[i] = arr[left + i];
	for (j = 0; (j + n1)< n2; j++)
		tmp[j + n1] = arr[mid + 1 + j];

	i = 0;
	j = n1;
	k = left;
	while (i < n1 && j < n2) {
		if (tmp[i] <= tmp[j])
			arr[k++] = tmp[i++];
		else
			arr[k++] = tmp[j++];
	}
	while (i < n1)
		arr[k++] = tmp[i++];
	while (j < n2)
		arr[k++] = tmp[j++];
	for (int i = 0; i < n2; i++) {
		tmp[i] = 0;
	}
}

void quick_sort(int* arr, int left, int right) {
	if (left > right) return;
	int pivot = partition(arr, left, right);
	quick_sort(arr, left, pivot - 1);
	quick_sort(arr, pivot + 1, right);
}

int partition(int* arr, int left, int right) {
	int pivot;
	int i = left;
	int j = right;
	pivot = arr[left];
	while (i < j)
	{
		while ((arr[j] >= pivot) && (i < j))
			j--;
		if (i != j)
		{
			arr[i++] = arr[j];
		}
		while ((arr[i] <= pivot) && (i < j))
			i++;
		if (i != j)
		{
			arr[j--] = arr[i];

		}
	}
	arr[i] = pivot;
	return i;
}

int max_num(int* arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	int k=0;
	while (mx) {
		mx=(int)(mx / 10);
		k++;
	}
	return k;
}

void counting(int* arr, int* tmp, int n, int p) {
	int i, count[10] = {0};
	int num;
	for (i = 0; i < n; i++) {
		num = (arr[i] / p) % 10;
		count[num]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		num = (arr[i] / p) % 10;
		tmp[count[num] - 1] = arr[i];
		count[num]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = tmp[i];
}

void radix_sort(int* arr, int* tmp, int n)
{
	int p;
	int m = max_num(arr, n);
	for (int i = 0; i < m; i++) {
		p = (int)pow(10, i);
		counting(arr, tmp, n, p);
	}
}


