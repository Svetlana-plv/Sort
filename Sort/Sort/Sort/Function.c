#include <stdio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include "Sort.h"
#include "Function.h"

void swap(int* elem1, int* elem2) {
	int tmp = *elem2;
	*elem2 = *elem1;
	*elem1 = tmp;
}

void print_array(int* arr, int n) {
	for (int i=0; i < n; i++) {
		if (i<10 || i>n-11)
			printf("%d ", arr[i]);
	}
	printf("\n");
}

void copy_array(int* arr, int* tmp, int n) {
	for (int i = 0; i < n; i++)
		tmp[i] = arr[i];
}

void check_sort(int* arr, int n) {
	int unordered = 1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1]) {
			unordered = 0;
			printf("Array unsorted!\n");
		}
	}
	if (unordered) {
		printf("Array sorted!\n");
	}
}

void file_open(int* arr, int n, char* name) {
	FILE* new_file;
	//char name[] = "test_rand_100.txt";
	new_file = fopen(name, "r");
	//printf("%s", name);
	if (!new_file) {
		printf("Error\n");
		return 0;
	}
	for (int i=0; i < n; i++) {
		fscanf(new_file, "%d", &arr[i]);
	}
	fclose(new_file);
}

void choose_sort(int* arr, int* tmp, int n) {
	printf("\n Select sort:\n 1)Bubble\n 2)Insert\n 3)Select\n 4)Merge\n 5)Qick Sort\n 6)Raddix\n");
	int num;
	scanf_s("%d", &num);
	printf("\n");
	printf("Sourse array:\n");
	print_array(arr, n);
	printf("\n");
	time_t start = clock();
	switch (num) {
		case 1:
			bubble_sort(arr, n);
			break;
		case 2:
			insert_sort(arr, n);
			break;
		case 3:
			select_sort(arr, n);
			break;
		case 4:
			merge_sort(arr, 0, n-1);
			break;
		case 5:
			quick_sort(arr, 0, n-1);
			break;
		case 6:
			radix_sort(arr, tmp, n);
			break;
		default: printf("break");
			break;
	}
	time_t stop = clock();
	//printf("\n");
	double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("%lf seconds\n", time);
	printf("\n");
	printf("Sorted array:\n");
	print_array(arr, n);
	printf("\n");
	check_sort(arr, n);
	free(arr);
	free(tmp);
}

void choose_type_array() {

	printf(" Select type of array to sort:\n 1)Sort\n 2)Rand\n 3)Reverse sort\n");
	int num;
	scanf_s("%d", &num);
	int sz;
	printf(" Select size of array:\n 1)100\n 2)1000\n 3)10000\n 4)100000\n 5)1000000\n 6)10000000\n");
	scanf_s("%d", &sz);
	int n = pow(10, sz + 1);
	int* arr;
	int* tmp;
	arr = (int*)malloc(n * sizeof(int));
	tmp = (int*)malloc(n * sizeof(int));
	switch (num) {
	case 1:
		switch (sz) {
		case 1:
			file_open(arr, n, "test_sort_100.txt");
			break;
		case 2:
			file_open(arr, n, "test_sort_1000.txt");
			break;
		case 3:
			file_open(arr, n, "test_sort_10000.txt");
			break;
		case 4:
			file_open(arr, n, "test_sort_100000.txt");
			break;
		case 5:
			file_open(arr, n, "test_sort_1000000.txt");
			break;
		case 6:
			file_open(arr, n, "test_sort_10000000.txt");
			break;
		default: 
			printf("break\n");
			break;
		}
		break;
	case 2:
		switch (sz) {
		case 1:
			file_open(arr, n, "test_rand_100.txt");
			printf("in");
			print_array(arr, n);
			break;
		case 2:
			file_open(arr, n, "test_rand_1000.txt");
			break;
		case 3:
			file_open(arr, n, "test_rand_10000.txt");
			break;
		case 4:
			file_open(arr, n, "test_rand_100000.txt");
			break;
		case 5:
			file_open(arr, n, "test_rand_1000000.txt");
			break;
		case 6:
			file_open(arr, n, "test_rand_10000000.txt");
			break;
		default: 
			printf("break\n");
			break;
		}
		break;
	case 3:
		switch (sz) {
		case 1:
			file_open(arr, n, "test_unsort_100.txt");
			break;
		case 2:
			file_open(arr, n, "test_unsort_1000.txt");
			break;
		case 3:
			file_open(arr, n, "test_unsort_10000.txt");
			break;
		case 4:
			file_open(arr, n, "test_unsort_100000.txt");
			break;
		case 5:
			file_open(arr, n, "test_unsort_1000000.txt");
			break;
		case 6:
			file_open(arr, n, "test_unsort_10000000.txt");
			break;
		default: 
			printf("break\n");
			break;
		}
		break;

	default: 
		printf("break\n");
		break;
	}
	choose_sort(arr, tmp, n);

}

//int i = left;
//int j = right;
//int pivot = arr[left];
//while (i < j) {
//	while ((arr[j] >= pivot) && (i < j))
//		j--;
//	while ((arr[i] <= pivot) && (i < j))
//		i++;
//	if (left != right)
//	{
//		swap(&arr[i++], &arr[j++]);
//	}
//}
//swap(&arr[i], &arr[left]);
//return i;



// partition
//int pivot = arr[right];
//int i = left - 1;
//for (int j = left; j < right; j++) {
//	if (arr[j] < pivot) {
//		i++;
//		if (i != j)
//			swap(&arr[i], &arr[j]);
//	}
//}
//swap(&arr[right], &arr[i + 1]);
//return i + 1;




//while ((i < mid) && (j < right)) {
//	if (arr[i] <= arr[j])
//		tmp[k++] = arr[i++];
//	else
//		tmp[k++] = arr[j++];
//}
//while (i <= mid)
//tmp[k++] = arr[i++];
//
//while (j < right)
//	tmp[k++] = arr[j++];


//int i, j;
//printf("%d  %d %d\n", left, mid, right);
//i = left; j = mid;
//for (int k = left; k < right; k++) {
//	if ((i < mid) && (j < right)) {
//		if (arr[i] <= arr[j])
//			tmp[k] = arr[i++];
//		else
//			tmp[k] = arr[j++];
//	}
//	else {
//		if (i == mid)
//			tmp[k] = arr[j++];
//		else
//			tmp[k] = arr[i++];
//	}
//}

//int* p1 = &arr[left];
//int* p2 = &arr[mid + 1];
//int* p3 = &tmp[left];
//printf("%d  %d %d\n", left, mid, right);
//while ((p1 <= &arr[mid]) && (p2 <= &arr[right])) {
//	if (*p1 < *p2) {
//		*p3 = *p1;
//		p3++;
//		p1++;
//	}
//	else {
//		*p3 = *p2;
//		p3++;
//		p2++;
//	}
//	while (p1 <= &arr[mid]) {
//		*p3 = *p1;
//		p3++;
//		p1++;
//	}
//	while (p2 <= &arr[right]) {
//		*p3 = *p2;
//		p3++;
//		p2++;
//	}
//}

//int i, j, k;
//int n1 = mid - left + 1;
//int n2 = right - mid;
//
//int* L;
//int* R;
//L = (int*)malloc(n1 * sizeof(int));
//R = (int*)malloc(n2 * sizeof(int));
//for (i = 0; i < n1; i++)
//	L[i] = arr[left + i];
//for (j = 0; j < n2; j++)
//	R[j] = arr[mid + 1 + j];
//i = 0;
//j = 0;
//k = left;
//while (i < n1 && j < n2) {
//	if (L[i] <= R[j]) {
//		arr[k++] = L[i];
//		i++;
//	}
//	else {
//		arr[k++] = R[j];
//		j++;
//	}
//}
//while (i < n1) {
//	arr[k] = L[i];
//	i++;
//	k++;
//}
//while (j < n2) {
//	arr[k] = R[j];
//	j++;
//	k++;
//}
//free(L);
//free(R);



